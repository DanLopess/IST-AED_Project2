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

typedef struct node{
 Task task;
 struct node *next;
} *link;



link insertBegin(link head, int a);
link insertEnd(link head, int value);
void printList(link head);
int i
