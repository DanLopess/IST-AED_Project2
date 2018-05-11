/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: data.h
Project: Tasks management
*************
Description:
This heather file contains all of the structures
and functions' Prototypes of the data structure of type list
*************/
#ifndef LIST_H
#define LIST_H

typedef struct node{
 Item task;
 struct node *next;
} *link;

link newNode(Item i);
int repeatingNode(link Head, link Node); /*Checks if node already exists - maybe use hash table*/
void addNode(link Head, link Node); /*to decide: beginning or the end*/
void removeNode(link Head, Item i);
void printList(link Head);

#endif
