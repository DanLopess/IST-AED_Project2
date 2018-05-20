/************
*************
May 18th '18

All Rights Reserved © Daniel Lopes

File: path.c
Project: Tasks management
*************
Description:
This auxiliary file contains all the functions
of the path calculation
*************/
#include "task.h"

extern int criticalPathCalculated; /*Receives variable from main*/

void path(List x){
	if(!listEmpty(x)){
		Key duration;
		calculateEarlyStart(x);
		calculateLateStart(x);
		duration = highestEarlyFinish(x);
		criticalPathCalculated = 1;
		printCriticalPath(x);
		printf("project duration = %lu\n", duration);
	}
	else{
		printf("project duration = 0\n");
	}
}

void calculateEarlyStart(List x){
	link i,f;
	for(i = x->head; i != NULL; i=i->next){
		if(listEmpty(((Item)i->item)->dependencies)) /*If it is an origin task*/
			((Item)i->item)->early = 0;
		else{
			Key highestValue = 0;
			for(f = ((Item)i->item)->dependencies->head; f!=NULL;f=f->next){
				link tempNode = findNode(x,*(Key*)f->item,0); /*grabs the node that*/
				if((((Item)tempNode->item)->duration +			/*contains that id*/
				((Item)tempNode->item)->early) > highestValue){
					highestValue = ((Item)tempNode->item)->duration +
					((Item)tempNode->item)->early;
				}
			}
			((Item)i->item)->early = highestValue;
		}
	}
}
void calculateLateStart(List x){ /*Cannot calculate late start*/
	link i,f;
	for(i = x->head; i != NULL; i=i->next){
		if(!isDependency(x,((Item)i->item)->id)){ /*If it is a final task*/
			((Item)i->item)->late = ((Item)i->item)->early;
			for(f = ((Item)i->item)->dependencies->head; f!=NULL;f=f->next){

			}
		}
	}
}

void printCriticalPath(List x){ /*prints tasks that have equal early and late*/
	link i;
	for(i = x->head; i != NULL; i = i->next){
		if(((Item)i->item)->early == ((Item)i->item)->late)
			printItem((Item)i->item);
	}
}

Key highestEarlyFinish(List a){
	link i;
	Key highest = 0;
	for(i = a->head; i != NULL; i=i->next)
		if((((Item)i->item)->duration + ((Item)i->item)->early) > highest)
			highest = (((Item)i->item)->duration + ((Item)i->item)->early);
	return highest;
}
