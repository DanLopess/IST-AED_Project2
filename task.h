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
  link dependencies; /*Pointer to list of dependencies*/
} Task;

typedef Task Item;

/* Function Declaration/Prototype */
void createTask(Item task);
void duration();
void depend();
void removes();
void path();
void exit();

#endif
/*
NOTES:
criar estrutura tarefa
criar lista de tarefas
criar lista de dependencias
criar hashtable para encontrar rapidamente tarefas
- max 1milh elementos
- utilizar nrs primos
- começar tabela com NULL
*/
