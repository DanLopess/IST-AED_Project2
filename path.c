/************
*************
May 18th '18

All Rights Reserved © Daniel Lopes

File: path.c.h
Project: Tasks management
*************
Description:
This auxiliary file contains all the functions
of the path function
*************/
#include "task.h"

extern int criticalPathCalculated; /*Receives variable from main*/

int isDependency(List x, Key id){ /*sees if it is dependent on any task(find tarefa origem)*/
}

void path(List x){ /*nao recalcular os elementos ja calculados*/
	link i;
	if(!listEmpty(x)){
		Key duration;
		calculateLateStart(x);
		calculateLateStart(x);
		duration = highestEarlyFinish(x);
		printCriticalPath(x);
		printf("project duration = %lu", duration);
		criticalPathCalculated = 1;
	}
}

void calculateEarlyStart(List x){
	link i;
	for(i = x->head; i != NULL; i=i->next){
		if(listEmpty(((Item)i->item)->dependencies)){
			((Item)i->item)->early = 0;
		}
		else{
			((Item)i->item)->early = highestEarlyFinish(((Item)i->item)->dependencies);
		}
	}
}
void calculateLateStart(List x){

}
void printCriticalPath(List x){ /*prints tasks that have equal early and late*/
}
Key highestEarlyFinish(List a){
	link i;
	Key highest = a->head->item;
	for(i = a->head; i != NULL; i=i->next){

	}
}
