/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: task.c
Project: Tasks management
*************
Description:
This auxiliary file contains all the declarations
and structures related to tasks
*************/

#define MAXDESCRIPTION 8000

typedef struct{
  unsigned long int id;
  char description[MAXDESCRIPTION+1];
  unsigned long int duration, early, late;
  link dependencies;


} Task;


/*
NOTES:
criar estrutura tarefa
criar lista de tarefas
criar lista de dependencias
criar hashtable para encontrar rapidamente tarefas
*/
