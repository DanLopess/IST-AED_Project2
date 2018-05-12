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
- Quando utilizo uma funcao para algo, se é parecido, tentar converter numa
- usar hash table
- resolver problema de ter tipo List em task.h
- list.c esta abstrato funciona sempre com tipo Item
*************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "task.h"

/* Pre-processed constants and structures*/
#define MAXCOMMAND 10 /*Command won't be bigger than 10 chars*/

/* Main Function */
int main(){
	/*int quitProgram = 0;
	char *command;

	do{
		scanf("%s*[" "]", command);
	} while(quitProgram == 0);*/

	List a; /*Contains head and tail*/
	Item task1, task2, task3;
	a = (List) malloc(sizeof(struct list)); /*Creates a list (head and tail)*/
	listInit(a);
	task1.id = 123;
	strcpy(task1.description, "ola tudo bem");
	task1.duration = 23;
	link node1 = newNode(task1, NULL); /*Allocs memory*/
	addNode(a,node1);
	task2.id = 456;
	strcpy(task2.description, "sup");
	task2.duration = 114;
	link node2 = newNode(task2, NULL); /*Allocs memory*/
	addNode(a,node2);
	task3.id = 90240525245;
	strcpy(task3.description, "ehehehehehehhehehe");
	task3.duration = 242424121446426;
	link node3 = newNode(task3, NULL); /*Allocs memory*/
	addNode(a,node3);
	printList(a);
	removeNode(a, node3);
	link node4 = newNode(task2, NULL); /*Allocs memory*/
	addNode(a,node4);
	printList(a);
	free(node1);
	free(node2);
	free(node4);
	free(a);


	return 0;
}

/* Function Implementation */
