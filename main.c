/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: main.c
Project: Tasks management
*************
Known Bugs:
-
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

/* Main Function */
int main(){
	int quitProgram = 0;
	char command[MAXSIZE+1];
	List a;
	a = (List) malloc(sizeof(struct list)); /*Creates a list (head and tail)*/
	listInit(a);
	do{
		scanf("%10s*[' ']", command); /*Reads until a space is found and MAXCOMMAND*/
		if(!strcmp(command,"exit"))
			quitProgram = 1;
		else{
			executeCommand(command, a);
		}
	} while(quitProgram == 0);
	deleteList(a); /* Frees all the memory of the list*/
	return 0;
}

/* Function Implementation */
void executeCommand(char *command, List x){
	if (!strcmp(command, "add")){
		addTask(x);
	}
	else if(!strcmp(command, "duration")){
		duration(x);
	}
	else if(!strcmp(command, "depend")){

	}
	else if(!strcmp(command, "remove")){
		removeTask(x);

	}
	else if(!strcmp(command, "path")){

	}
	else{
		printf("illegal arguments");
	}
}
