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
*	Function: listInit
* --------------------
*	initiate the list with NULL
*	input: list that contains certain items
*	returns: nothing
*/
void listInit(List x) {
	x->head = NULL;
	x->tail = NULL;
}

/*
* Function: listEmpty
* --------------------
*	checks if head is NULL which means that the list is empty
*	input: list that contains certain items
*	returns: nothing
*/
int listEmpty(List x) { /*Checks if list is empty*/
	return x->head == NULL;
}

/*
*	Function: deleteList
* --------------------
*	deletes all the elements on the list and puts the head and tail as NULL
*	input: receives a list of items
*	returns: nothing
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
*	Function: addNode
*	--------------------
*	adds a node to a given list with a given item
*	input: a list with certain items and a void pointer to item
*	returns: nothing
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
*	Function: newNode
* --------------------
*	creates a new node and allocates memory to it
*	input: void pointer to an item and a link which indicates the next node
*	returns: a pointer to a node (link)
*/
link newNode(void* i, link next) {
	link x = (link) malloc(sizeof(struct node));
	x->item = i;
	x->next = next;
	return x;
}

/*
*	Function: removeNode
* --------------------
*	removes a given id by freeing the memory stored in the pointer link
* the fact that this function can remove nodes with type Item and nodes with
*	type Key allows for a more efficient removal overall
*	input: a list of nodes and a given id
*	returns: nothing
*/
void removeNode(List x, Key id, int control){
	if(!listEmpty(x)){
		link temp = x->head, prev;
		if(control){ /*look for in global list control == 1*/
			if (temp != NULL && ((Item)temp->item)->id == id){
				if(x->head == x->tail) /*if only one element on the list*/
					x->tail = temp->next;
				x->head = temp->next;
				free(temp);
				return;
			}
			prev = temp;
			while (temp != NULL && ((Item)temp->item)->id != id){
				prev = temp;
				temp = temp->next;
			}
		}
		else{ /*look for in dependencies control == 0*/
			if (temp != NULL && *((Key*)(Item)temp->item) == id){
				if(x->head == x->tail) /*if only one element on the list*/
					x->tail = temp->next;
				x->head = temp->next;
				free(temp);
				return;
			}
			prev = temp;
			while (temp != NULL && *((Key*)(Item)temp->item) != id){
				prev = temp;
				temp = temp->next;
			}
		}
	/* If node was not present in linked list */
	if (temp == NULL) return;
	/* Unlink the node from linked list */

	prev->next = temp->next;
	free(temp);
	}
}
