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

void addNode(List x, link node) { /*Adds a node to a certain list*/
	if (listEmpty(x)) {
		x->head = node;
		x->tail = node;
		return;
	}
	x->tail->next = node;
	x->tail = x->tail->next;
}

int existantNode(List x, link node){ /*Substitute for hash table*/
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

void removeNode(List x, link node){ /* Finish remove */
	link i;
	if (node == x->head){ /*If node is the first one, need to change head*/
		x->head = x->head->next;
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

void printList(List x)
{
	link t;
	int i=1;
	if (listEmpty(x)){
		printf("Empty List\n");
	}
	else{
		for(t = x->head; t != NULL; t = t->next){
			printf("Node %d:\n", i); i++;
			/*printTask(t->item); PLACE IN PRINTTASK*/
			printf("ID = %ld\n",t->item.id);
			printf("Description = %s\n", t->item.description);
			printf("Duration = %ld\n", t->item.duration);
		}
	}
}
