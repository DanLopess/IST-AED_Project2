/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: list.h
Project: Tasks management
*************
Description:
This heather file contains all of the structures
and functions' Prototypes of the data structure of type list
*************/

#ifndef LIST_H
#define LIST_H
#include "task.h"

typedef struct node *link; /* link is a pointer to struct node */
typedef struct list *List; /* *List is a struct list */

struct node{ Item item; link next; };
struct list { link head; link tail; };

List listInit(List x);
int listEmpty(List x);
link newNode(Item i, link next);
int repeatingNode(List x, link node); /*Checks if node already exists - maybe use hash table*/
void addNode(List x, link node); /* add to end, use head and tail*/
Item getFirstElement(List x);
void removeNode(List x, link node);
void printList(List x);

#endif
