/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: task.h
Project: Tasks management
*************
Description:
This auxiliary file contains all the declarations
and structures related to tasks
*************/
#ifndef TASK_H
#define TASK_H
#define MAXDESCRIPTION 8000

typedef unsigned long int Key;
typedef struct list *List; /* *List is a struct list defined in list.h*/

typedef struct task{
	char description[MAXDESCRIPTION+1];
	Key id,duration, early, late;
	List dependencies; /* List that contains id of dependencies */
}*Item; /*this Item is a pointer to Item*/

#include "list.h"

/*Function Declaration/Prototype*/
void cleanBuffer();
Item readItem(List x);
void addItem(Item task, List x);
void removeItem(List x);
void printItem(Item t);
void duration(List x);
void depend(List x);
void path(List x);
int nonExistant(List x, Key id);
void deleteAllTasks(List x);

#endif
