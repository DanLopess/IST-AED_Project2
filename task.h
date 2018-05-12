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

#include "list.h"

typedef struct{
	char description[MAXDESCRIPTION+1];
	unsigned long int id,duration, early, late;
	/*List dependencies; Pointer to list of dependencies, head and tail of a list*/
} Item; /*this Item is a Task*/


/*Function Declaration/Prototype*/
Item createTask(char *description, unsigned long int id, unsigned long int duration);
void add(Item task, List x);
void duration();
void depend();
void removes();
void path();
void exit();


#endif
