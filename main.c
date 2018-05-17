/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: main.c
Project: Items management
*************
Known Bugs:
- Add, falta 1 Free
- Remove causa erro
- duration está correto
- fazer hash table
Notes:
- Comentarios das funcoes fora das funcoes
- Quando utilizo uma funcao para algo, se é parecido, tentar converter tudo em uma
- usar hash table
- trocar existantID para hashtable

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

	while(scanf("%10s*[' ']", command) == 1){
		if(!strcmp(command,"exit"))
			break;
		else
			executeCommand(command, a);
	}
	deleteAllTasks(a); /* Frees all the memory of the list*/
	return 0;
}

/* Function Implementation */
void executeCommand(char *command, List x){
	/*char c;*/
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
	/*while((c = getchar()) != '\n'); cleans buffer*/
}
