/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: task.c
Project: Tasks management
*************
Description:
This auxiliary file contains all the implementations to tasks
*************/
#include "task.h"

/* Function Declaration/Prototype */
Item createTask(char *description, unsigned long int id, unsigned long int duration){
	Item task;
	strcpy(task.description, description);
	task.id = id;
	task.duration = duration;
	return task;
}

void add(Item task, List x){
	link node = newNode(task,NULL); /*Adds to end so next will be NULL*/
	addNode(x,node);
}

void duration();
void depend();
void removes();
void path();
void exit();
