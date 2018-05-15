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

void listInit(List x) {
	x->head = NULL;
	x->tail = NULL;
}

int listEmpty(List x) { /*Checks if list is empty*/
	return x->head == NULL;
}

void deleteList(List x){
	link t,a;
	if(!listEmpty(x)){
		for(t = x->head; t->next != NULL; t = t->next){
			a = t->next;
			t->next = a->next;
			free(a);
		}
	}
	free(x->head);
	free(x->tail);
}

link newNode(void* i, link next) {
	link x = (link) malloc(sizeof(struct node));
	x->item = i;
	x->next = next;
	return x;
}

void addNode(List x, link node) { /*Adds a node to a certain list*/
	if (listEmpty(x)) {
		x->head = node;
		x->tail = node;
		return;
	}
	x->tail->next = node;
	x->tail = x->tail->next;
}

void removeNode(List x, link node){ /* Finish remove */
	link i;
	if (node == x->head){ /*If node is the first one, need to change head*/
		x->head = x->head->next;
		free(node);
	}
	else if(node == x->tail && node == x->head){
		x->head = NULL;
		x->tail = NULL;
		free(node);
	}
	else{
		for (i = x->head; i != NULL; i = i->next)
			if (i->next == node){
				if(node == x->tail){ /*If node is the last one, need to change tail*/
					i->next = NULL;
					x->tail = i;
				}
				else{
					i->next = node->next;
				}
				free(node);
				break;
			}
	}
}
