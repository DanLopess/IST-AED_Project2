/************
*************
May 18th '18

All Rights Reserved © Daniel Lopes

File: task.c
Project: Tasks management
*************
Description:
This auxiliary file contains all the implementations of the
main functions and also auxiliary functions
*************/
#include "task.h"

extern int criticalPathCalculated; /*Receives variable from main*/

/*
* Function: cleanBuffer
* --------------------
*  clears the buffer of the standard input
*  input: nothing
*  returns: nothing
*/
void cleanBuffer(){
	char c;
	while((c=getchar()) != '\n');
}

/*
*	Function: readItem
*	--------------------
*	reads the task and all its elements apart from the dependencies which
*	are read in addItem
*	input: List x which contains all of the tasks
*	returns: an Item, i.e., the task that was read
*/
Item readItem(List x){ /*Reads a certain task without dependencies*/
	long int id,duration; /*allows to decide if a negative number was read*/
	Item task = (Item)malloc(sizeof(struct task));
	if(scanf("%ld \"%8001[^\"]\"%ld*['\n']",&id,task->description,&duration) != 3){
		printf("illegal arguments\n");
		cleanBuffer();
		free(task);
		return NULL;
	}
	else{
		if(!nonExistant(x,id)){
			printf("id already exists\n");
			cleanBuffer();
			free(task);
			return NULL;
		}
		else if(id > 0 && duration > 0){
			task->id = (Key)id;
			task->duration = (Key)duration;
			return task;
		}
		else{
			printf("illegal arguments\n");
			cleanBuffer();
			free(task);
			return NULL;
		}
	}
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void addItem(Item task, List x){
	Key readId;
	int readDependency = 0;

	if(task != NULL){
		task->dependencies = (List) malloc(sizeof(struct list));
		listInit(task->dependencies);
		while(scanf("%lu", &readId) == 1 && readId > 0){
			readDependency = 1;
			if(nonExistant(x,readId)){
				printf("no such task\n");
				deleteList(task->dependencies);
				free(task->dependencies);
				free(task);
				return;
			}
			else{
				Key *tempId = (Key*) malloc(sizeof(Key));
				*tempId = readId;
				addNode(task->dependencies,tempId);
			}
		}
		if(!readDependency){
			deleteList(task->dependencies);
		}
		addNode(x,task);
		criticalPathCalculated = 0;
	}
	else
		free(task);
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
int nonExistant(List x, Key id){
	link i;

	for(i = x->head; i != NULL; i = i->next)
		if(((Item)i->item)->id == id)
			return 0; /*existant*/
	return 1; /*nonexistant*/
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void removeItem(List x){
	link i;
	Key id;
	int nodeRemoved=0;

	if(scanf("%lu*['\n']", &id)==1){
		if(!nonExistant(x,id)){
			for (i = x->head; i != NULL; i = i->next){
				if(((Item)i->item)->id == id){ /* item is void* so it needs to be casted*/
					if(listEmpty(((Item)i->item)->dependencies)){ /*If it has zero dependencies*/
						removeNode(x,i);
						removeDependency(x,id);
						nodeRemoved = 1;
						criticalPathCalculated = 0;
						break;
					}
					else{
						printf("task with dependencies\n");
						nodeRemoved = 1;
					}
				}
			}
			if (!nodeRemoved)
				printf("no such task\n");
		}
		else
			printf("no such task\n");
	}
	else{
		printf("illegal arguments\n");
	}
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void removeDependency(List x, Key id){ /*removes from all lists of dependencies*/
	link i,f;
	for(i = x->head; i!=NULL; i=i->next){
		for(f = ((Item)i->item)->dependencies->head; f!=NULL; f=f->next)
			if(*(((Key*)f->item)) == id)
				removeNode(((Item)i->item)->dependencies,f);
	}
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void printItem(Item t){
	link i;

	printf("%ld \"%s\" %ld",t->id, t->description, t->duration);
	if(!listEmpty(t->dependencies))
		for(i = t->dependencies->head; i != NULL; i = i->next){
			printf(" %lu", *((Key*)i->item));
		}
	printf("\n");
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void duration(List x){
	Key duration;
	link i;
	int test = scanf("%lu*['\n']", &duration);

	if(!criticalPathCalculated){
		if(test == 1 && duration > 0){
				for(i = x->head; i != NULL; i = i->next){
					if(((Item)i->item)->duration >= duration)
						printItem(i->item);
				}
		}
		else{
			if(test == 1 && duration < 0)
				printf("illegal arguments");
			else if(test == 0){
				for(i = x->head; i != NULL; i = i->next)
					printItem(i->item);
			}
		}
	}
	else{
		/*print early and start*/
	}
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void depend(List x){
	Key id;
	if (scanf("%lu*[^'\n']", &id) == 1 && id > 0){
		link i,f;
		int foundDependency = 0;
		if(!nonExistant(x,id)){
			printf("%lu:",id);
			for(i = x->head; i != NULL; i = i->next){
				if(!listEmpty(((Item)i->item)->dependencies))
					for(f = ((Item)i->item)->dependencies->head; f != NULL; f = f->next){
						if(*(Key*)f->item == id){
							printf(" %lu", ((Item)i->item)->id);
							foundDependency = 1;
							break;
						}
					}
			}
			if(!foundDependency){
				printf(" no dependencies\n");
			}
			else{
				printf("\n");
			}
		}
		else{
			printf("no such task\n");
		}
	}
	else{
		printf("illegal arguments\n");
		cleanBuffer();
	}
}

/*
*	Function: addItem
*	--------------------
*	reads the dependencies and adds them to the dependencies list and also adds
*	the task to the main list
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void deleteAllTasks(List x){ /*Delete list of tasks*/
	link t;
	if(!listEmpty(x)){
		for(t = x->head; t->next != NULL; t = t->next){
			deleteList(((Item)t->item)->dependencies);
			free(((Item)t->item)->dependencies); /*now free the list completely*/
		}
	}
	deleteList(x);
	free(x);
}
