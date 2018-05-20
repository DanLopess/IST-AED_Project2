/************
*************
May 18th '18

All Rights Reserved © Daniel Lopes

File: main.c
Project: Items management
*************
Known Bugs:
- add done
- duration done
- depend done
- remove not done
- path not done

*************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task.h"

/* Pre-processed constants and structures*/
#define MAXSIZE 10 /*Size of Command which won't be bigger than 10 chars*/

/* Function Declaration/Prototype */
void executeCommand(char *command, List x);

/*Global variables*/
int criticalPathCalculated = 0; /*controls the status of the critical Path */

/* Main Function */
int main(){
	char command[MAXSIZE+1];
	List a;
	a = (List) malloc(sizeof(struct list)); /*Creates a List (head and tail)*/
	listInit(a);

	while(scanf("%10s*['\n']", command) == 1){
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
	else if(!strcmp(command, "path")){
		path(x);
	}
	else{
		printf("illegal arguments\n");
	}
}
