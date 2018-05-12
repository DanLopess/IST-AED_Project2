/************
*************
May 12th '18

All Rights Reserved © Daniel Lopes

File: list.c
Project: Tasks management
*************
Description:
This auxiliary file contains all the implementations
of the functions in the data structure of type list with the help
of FIFO ADTs
*************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List listInit(List x) {
	x->head = NULL;
	x->tail = NULL;
}

int listEmpty(List x) { /*Checks if list is empty*/
	return x->head == NULL;
}

link newNode(Item i, link next) {
	link x = (link) malloc(sizeof(struct node));
	x->item = i;
	x->next = next;
	return x;
}

void addNode(List x, Item i) { /*Adds a node to a certain list*/
	link head = x->head;
	link tail = x->tail;
	link node = newNode(i, head);
	if (listEmpty(x)) {
		head = (tail = node);
		free(node);
		return;
	}
	tail->next = node;
	tail = tail->next;
	free(node);
}

int repeatingNode(List x, link node){ /*Substitute for hash table*/
	link i;
	for (i = x->head; i != NULL; i = i->next)
		if (i == node){
			return 1; /*Node already exists*/
		}
	return 0; /*Node non-existant*/
}


Item getFirstElement(List x) { /*Removes first element of list and returns it*/
	Item item = x->head->item;
	link t = x->head->next;
	free(x->head);
	x->head = t;
	return item;
}

void removeNode(List x, link node){
	link i, aux;
	for (i = x->head; i != NULL; i = i->next)
		if (i->next == node){
			aux = i->next;
			i->next = aux->next;
			free(aux);
		}
}

void printList(List x)
{
	link t;
	int i=0;
	if (listEmpty(x)){
		printf("Empty List");
	}
	else{
		for(t = x->head; t != NULL; t = t->next){
			printf("Node %d:\n", i); i++;
			/*printTask(t->item);*/
			printf("ID = %ld\n",t->item.id);
			printf("Description = %s", t->item.description);
			printf("Duration = %ld", t->item.duration);
		}
	}
}
