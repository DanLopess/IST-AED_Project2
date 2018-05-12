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

typedef struct{
	unsigned long int id;
	char description[MAXDESCRIPTION+1];
	unsigned long int duration, early, late;
	/*List dependencies; Pointer to list of dependencies, head and tail of a list*/
} Item; /*this Item is a Task*/


/* Function Declaration/Prototype
void createTask(Item task);
void duration();
void depend();
void removes();
void path();
void exit();
*/

#endif
