/************
*************
May 18th '18

All Rights Reserved © Daniel Lopes

File: main.c
Project: Items management
*************
Known Bugs:
- path doesn't work
*************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task.h"

/* Pre-processed constants and structures*/
#define MAXSIZE 8 /*Size of Command which won't be bigger than 8 chars*/

/* Function Declaration/Prototype */
void executeCommand(char *command, List x);
void First(List x);
void Second(List x);

/*Global variables*/
int criticalPathCalculated = 0; /*controls the status of the critical Path */

/* Main Function */
int main(){
	char command[MAXSIZE+1];
	List a;
	a = (List) malloc(sizeof(struct list)); /*Creates a List (head and tail)*/
	listInit(a);

	while(scanf("%8s*['\n']", command) == 1){
		if(!strcmp(command,"exit")){
			cleanBuffer();
			break;
		}
		else
			executeCommand(command, a);
	}
	deleteAllTasks(a); /* Frees all the memory of the list*/
	return 0;
}

/*
*	Function: executeCommand
*	--------------------
*	executes all the commands based on the input read in main
*	input: *command which contains the given command, and the list x
*	that contains all of the tasks
*	returns: nothing
*/
void executeCommand(char *command, List x){
	if (!strcmp(command, "add")){
		addItem(readItem(x),x);
	}
	else if(!strcmp(command, "duration")){
		duration(x);
	}
	else if(!strcmp(command, "depend")){
		depend(x);
	}
	else if(!strcmp(command, "remove")){
		removeItem(x);
	}
	else if(!strcmp(command, "first")){
		First(x);
	}
	else if(!strcmp(command, "second")){
		Second(x);
	}
	else if(!strcmp(command, "path")){
		/*path(x); path isn't working*/
	}
	else{
		printf("illegal arguments\n");
	}
}

void First(List x){
	Key id;
	link tempNode;
	char description[MAXDESCRIPTION+1];
	if(scanf("%lu \"%8001[^\"]\"",&id,description) == 2){
		tempNode = findNode(x,id,0);
		if(tempNode != NULL){
			strcpy(((Item)tempNode->item)->description, description);
		}
		else{
			printf("no such task");
		}
	}
}
void Second(List x){
	link i;
	printf("sources:");
	for(i = x->head; i != NULL; i = i->next){
		if(listEmpty(((Item)i->item)->dependencies)){
			printf(" %lu", ((Item)i->item)->id);
		}
	}
	printf("\nsinks:");
	for(i = x->head; i != NULL; i = i->next){
		if(!isDependency(x,((Item)i->item)->id)){
			printf(" %lu", ((Item)i->item)->id);
		}
	}
}
