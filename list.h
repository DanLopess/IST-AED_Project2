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

typedef struct node *link; /* link is a pointer to struct node */

#include "task.h"

struct node { void* item; link next; }; /*Receives a certain item*/
struct list { link head; link tail; }; /*Representation of a Queue*/

void listInit(List x);
int listEmpty(List x);
void deleteList(List x);
link newNode(void*  i, link next);
void addNode(List x, void* item);
void removeNode(List x, link node);

#endif
