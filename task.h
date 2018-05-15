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

typedef struct list *List; /* *List is a struct list defined in list.h*/

typedef struct task{
	char description[MAXDESCRIPTION+1];
	unsigned long int id,duration, early, late;
	List dependencies; /**/
}*Task; /*this Task is a pointer to task */


#include "list.h"

/*Function Declaration/Prototype*/
link findNodeById(List x, unsigned long int id);
void addTask(List x);
void removeTask(List x);
void printTask(Task task);

void duration(List x);
void depend();
void removes();
void path();

#endif
