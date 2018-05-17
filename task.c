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
#include "hash.h"

void cleanBuffer(){
	char c;
	while((c=getchar()) != '\n');
}

Item readItem(List x){ /*Reads a certain task without dependencies*/
	Item task = (Item)malloc(sizeof(struct task));
	if(scanf("%lu \"%8001[^\"]\"%lu",&task->id,task->description,&task->duration) != 3){
		printf("illegal arguments\n");
		cleanBuffer();
		free(task);
		return NULL;
	}
	else{
		if(!nonExistant(x,task->id)){ /*replace for STsearch*/
			printf("id already exists\n");
			cleanBuffer();
			free(task);
			return NULL;
		}
		else if(task->id > 0 && task->duration > 0){
			return task;
		}
		else{
			printf("illegal arguments\n");
			cleanBuffer();
			free(task);
			return NULL;
		}
	}
}

void addItem(Item task, List x){
	Key readId;
	int readDependency = 0;

	if(task != NULL){
		task->dependencies = (List) malloc(sizeof(struct list));
		listInit(task->dependencies);
		/*---------------------Taking care of dependencies---------------------*/
		while(scanf("%lu*['\n']", &readId) == 1){
			readDependency = 1;
			if(nonExistant(x,readId)){ /*replace for STsearch*/
				printf("no such task\n");
				free(task->dependencies);
				free(task);
				return;
			}
			else{
				Key *tempId = (Key*) malloc(sizeof(Key));
				tempId = &readId;
				/*verificar se ja existe na hashtable*/
				printf("adding dependencie: %lu\n", readId);
				addNode(task->dependencies,tempId);
			}
		}
		/*---------------------------------------------------------------------*/
		/*ADD HERE-ID TO HASHTABLE*/
		if(!readDependency){
			deleteList(task->dependencies);
		}
		addNode(x,task); /* also apply to STinsert*/
	}
}

int nonExistant(List x, Key id){ /*replace for hash table*/
	link i;

	for(i = x->head; i != NULL; i = i->next)
		if(((Item)i->item)->id == id)
			return 0; /*existant*/
	return 1; /*nonexistant*/
}

void removeItem(List x){ /*If task has dependencies can't be removed*/
	link i;
	Key id;
	int nodeRemoved=0;

	scanf("%lu", &id);
	if(!nonExistant(x,id)){ /*replace for STsearch*/
		for (i = x->head; i != NULL; i = i->next){
			if(((Item)i->item)->id == id){ /* item is void* so it needs to be casted*/
				if(listEmpty(((Item)i->item)->dependencies)){ /*If it has zero dependencies*/
					removeNode(x,i); /* also apply to STdelete*/
					nodeRemoved = 1;
					break;
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

void printItem(Item t){
	link i;

	printf("%ld \"%s\" %ld ",t->id, t->description, t->duration);
	if(!listEmpty(t->dependencies))
		for(i = t->dependencies->head; i != NULL; i = i->next){
			Key id =  *((Key*)i->item);
			printf(" %lu", id);
		}
	printf("\n");
}

void duration(List x){
	Key duration;
	link i;
	if(scanf("%lu*['\n']", &duration) == 1)
		for(i = x->head; i != NULL; i = i->next){
			if(((Item)i->item)->duration >= duration)
				printItem(((Item)i->item));
		}
	else{
		for(i = x->head; i != NULL; i = i->next)
			printItem(((Item)i->item));
	}
}


void depend(List x){ /*BUGS*/
	Key id;
	link i;
	int foundDependency = 0;
	if (scanf("%lu", &id) == 1){
		if(!nonExistant(x,id)){ /*replace for STsearch*/
			for(i = x->head; i != NULL; i = i->next){
				if(((Item)i->item)->id == id){ /*fazer outro for para ver as dependencias e meter break*/
					printItem(((Item)i->item));
					foundDependency = 1;
				}
			}
			if(!foundDependency){
				printf("%lu: no dependencies\n", id);
			}
		}
		else{
			printf("no such task\n");
		}
	}
	else
		printf("no such task\n");
}


void deleteAllTasks(List x){ /*Delete list of tasks*/
	link t;
	if(!listEmpty(x)){
		for(t = x->head; t->next != NULL; t = t->next){
			deleteList(((Item)t->item)->dependencies);
			free(((Item)t->item)->dependencies); /*now free the list completely*/
		}
	}
	deleteList(x);
	free(x);
}

void path(List x){ /*nao recalcular os elementos ja calculados*/

}
