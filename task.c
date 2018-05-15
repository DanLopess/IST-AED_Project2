/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: task.c
Project: Tasks management
*************
Description:
This auxiliary file contains all the implementations to tasks
*************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"

/* Function Declaration/Prototype */
link findNodeById(List x, unsigned long int id){
	link i;
	for(i = x->head; i != NULL; i = i->next)
		if(i->item->id == id)
			return i;
	return NULL; /*non-existant node*/
}

void addTask(List x){
	char c;
	Item task = (Item)malloc(sizeof(struct task));
	unsigned long int tempId;
	link node, tempNode = (link) malloc(sizeof(struct node));
	task->dependencies = (List) malloc(sizeof(struct list));
	/* -------------------------- Reading the task -------------------------*/
	scanf("%lu", &task->id);
	tempNode = findNodeById(x,task->id); /*Substitute for hashtable*/
	if(tempNode==NULL){
		while((c=getchar())==' ');
		if (c == '\"')
			scanf ("%[^\"]%*c", task->description); /*reads descrp with spaces until " */
		scanf("%lu", &task->duration);
		listInit(task->dependencies);
		/*---------------------Taking care of dependencies---------------------*/
		while(scanf("%lu", &tempId) == 1){
			tempNode = findNodeById(x,tempId);
			if(tempNode==NULL){
				printf("no such task\n");
				free(task->dependencies);
				free(task);
				free(tempNode);
			}
			addNode(task->dependencies,tempNode); /*adds a new dependency*/
		}
		/*---------------------------------------------------------------------*/
		node = newNode(task,NULL); /*creates the node*/
		addNode(x, node);
	}
	else{
		printf("id already exists\n");
		free(task->dependencies);
		free(task);
		free(tempNode);
	}
}


void removeTask(List x){ /*If task has dependencies can't be removed*/
	link i;
	unsigned long int id;
	int nodeRemoved=0;
	scanf("%lu", &id);

	if(!listEmpty(x)){
		for (i = x->head; i != NULL; i = i->next){
			if(i->item->id == id){
				if(listEmpty(i->item->dependencies)){ /*If it has zero dependencies*/
					removeNode(x,i); /*remover tambem da hashtable e das dependencias*/
					nodeRemoved = 1;
				}
				else{
					printf("task with dependencies\n");
					nodeRemoved = 1;
				}
			}
		}
		if (!nodeRemoved)
			printf("no such task\n"); /*trocar para procurar na hashtable*/
	}
	else
		printf("no such task\n");
}

void printTask(Item task){
	link i;

	printf("%ld %s %ld",task->id, task->description, task->duration);
	for(i = task->dependencies->head; i != NULL; i = i->next){
		printf("%lu ",i->item->id);
	}
	printf("\n");
}

void duration(List x){
	unsigned long int duration;
	link i;
	if (scanf("%lu*['\n']", &duration) == 1){
		for(i = x->head; i != NULL; i = i->next)
			if(i->item->duration >= duration)
				printTask(i->item);
	}
	else{
		for(i = x->head; i != NULL; i = i->next)
			printTask(i->item);
	}
}

void depend();



void path(); /*nao recalcular os elementos ja calculados*/
