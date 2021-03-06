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
*	Function: nonExistant
*	--------------------
*	checks if an id exists in a certain list
*	input: List x which contains all of the tasks and an id
*	returns: an integer, either 0 (exists) or 1 (doesnt exist)
*/
int nonExistant(List x, Key id){
	link i;

	for(i = x->head; i != NULL; i = i->next)
		if(((Item)i->item)->id == id)
			return 0; /*existant*/
	return 1; /*nonexistant*/
}

/*
*	Function: removeItem
*	--------------------
*	reads a certain id and removes it from the list
*	input: List x which contains all of the tasks
*	returns: nothing
*/
void removeItem(List x){
	link i;
	Key id;
	int nodeRemoved=0;

	if(scanf("%lu*['\n']", &id)==1 && id > 0){ /*check task with dependencies*/
		if(!nonExistant(x,id)){
			if(isDependency(x,id)){
				printf("task with dependencies\n");
				nodeRemoved = 1;
			}
			else{
				for(i = x->head; i != NULL; i = i->next)
					if(((Item)i->item)->id == id){
						removeNode(x,i);
						removeDependency(x,id);
						nodeRemoved = 1;
						criticalPathCalculated = 0;
						break;
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
*	Function: removeDependency
*	--------------------
*	receives a list and an id and removes that id from all dependencies and sucessors
*	input: List x which contains all of the tasks and an id
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
*	Function: printItem
*	--------------------
*	prints a certain item
*	input: Item , i.e., tasks
*	returns: nothing
*/
void printItem(Item t){
	link i;

	if(!criticalPathCalculated){
	printf("%ld \"%s\" %ld",t->id, t->description, t->duration);
	if(!listEmpty(t->dependencies))
		for(i = t->dependencies->head; i != NULL; i = i->next){
			printf(" %lu", *((Key*)i->item));
		}
	printf("\n");
	}
	else{
		printf("%ld \"%s\" %ld",t->id, t->description, t->duration);
		if(t->early == t->late)
			printf(" [%lu CRITICAL]",t->early);
		else
			printf(" [%lu %lu]",t->early,t->late);
		if(!listEmpty(t->dependencies))
			for(i = t->dependencies->head; i != NULL; i = i->next){
				printf(" %lu", *((Key*)i->item));
			}
		printf("\n");
	}
}

/*
*	Function: duration
*	--------------------
*	based on a read value, which is a duration, prints out all the Tasks
* that have equal or superior duration to the read duration
*	input: List x which contains all of the tasks and an Item, i.e., task
*	returns: nothing
*/
void duration(List x){
	Key duration;
	link i;
	char c;
	if((c = getchar()) == ' '){
		int test = scanf("%lu", &duration);
		if(test == 1 && duration > 0){
				for(i = x->head; i != NULL; i = i->next){
					if(((Item)i->item)->duration >= duration)
						printItem(i->item);
				}
		}
		else{
			if(test == 1 && duration <= 0)
				printf("illegal arguments\n");
		}
	}
	else
		for(i = x->head; i != NULL; i = i->next)
			printItem(i->item);
}


/*
*	Function: depend
*	--------------------
*	prints out the input id of a certain task and all of the ids that
*	are dependant of that task
*	input: List x which contains all of the tasks
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
	}
}

/*
*	Function: deleteAllTasks
*	--------------------
*	deletes all of the allocated memory (dependencies, items and list of tasks)
*	input: List x which contains all of the tasks
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

/*
*	Function: isDependency
*	--------------------
*	sweeps the list and returns 1 if this id is a dependency of any task and 0 otherwise
*	input: List x which contains all of the tasks and an Id
*	returns: 0 or 1
*/
int isDependency(List x, Key id){ /*sees if it is dependent on any task*/
	link i,f;
	for(i = x->head; i != NULL; i = i->next){
		for(f=((Item)i->item)->dependencies->head; f != NULL; f = f->next){
			if(*(Key*)f->item == id)
				return 1; /*it is dependency*/
		}
	}
	return 0; /*not a dependency*/
}

/*
*	Function: isDependency
*	--------------------
*	sweeps the list and returns 1 if this id is a dependency of any task and 0 otherwise
*	input: List x which contains all of the tasks and an Id
*	returns: 0 or 1
*/
link findNode(List x, Key id){
	link i;
	if(!listEmpty(x)){
		for (i = x->head; i!= NULL; i=i->next)
			if(((Item)i->item)->id == id)
				return i;
	}
	return NULL;
}
