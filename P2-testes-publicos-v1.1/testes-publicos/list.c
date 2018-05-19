/************
*************
May 18th '18

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

/*
* Function: listInit
* --------------------
*  initiate the list with NULL
*  input: list that contains certain items
*  returns: nothing
*/
void listInit(List x) {
	x->head = NULL;
	x->tail = NULL;
}

/*
* Function: listEmpty
* --------------------
*  checks if head is NULL which means that the list is empty
*  input: list that contains certain items
*  returns: nothing
*/
int listEmpty(List x) { /*Checks if list is empty*/
	return x->head == NULL;
}

/*
* Function: deleteList
* --------------------
*  deletes all the elements on the list and puts the head and tail as NULL
*  input: receives a list of items
*  returns: nothing
*/
void deleteList(List x){ /*doesn't completely free the list on purpose*/
	if(!listEmpty(x)){
		link t = x->head, next;
		while (t != NULL){
			next = t->next;
			free(t->item);
			free(t);
			t = next;
		}
		x->head = NULL;
		x->tail = NULL;
	}
}

/*
* Function: addNode
* --------------------
*  sweeps the vector and finds the lowest line
*  input: *matrix (vector of type matrixElement),int inf_l, int sup_l
*  returns: a line number
*/
void addNode(List x, void* item) {
	if (listEmpty(x)) {
		x->head = (x->tail = newNode(item, x->head));
		return;
	}
	x->tail->next = newNode(item, x->tail->next);
	x->tail = x->tail->next;
}

/*
* Function: minLine
* --------------------
*  sweeps the vector and finds the lowest line
*  input: *matrix (vector of type matrixElement),int inf_l, int sup_l
*  returns: a line number
*/
link newNode(void* i, link next) {
	link x = (link) malloc(sizeof(struct node));
	x->item = i;
	x->next = next;
	return x;
}

/*
* Function: minLine
* --------------------
*  sweeps the vector and finds the lowest line
*  input: *matrix (vector of type matrixElement),int inf_l, int sup_l
*  returns: a line number
*/
void removeNode(List x, link node){
	link i;
	if (node == x->head){ /*If node is the first one, need to change head*/
		x->head = node->next;
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
