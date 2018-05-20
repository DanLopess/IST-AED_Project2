#ifndef HASH_H
#define HASH_H

#include "task.h"

/* Key type of Hash table */
#define key(a) (a->id)
#define NULLitem(a) (NULL)
#define eq(a,b) (a==b) /*equality between keys */

/*Function Declaration/Prototype*/
void STinit(int m);
void STinsert(void* item);
void STdelete(void* item);
Item STsearch(Key v);

#endif
