#ifndef HASH_H
#define HASH_H

#include "task.h"

/* Key type of Hash table */
#define key(a) (a->id)
#define NULLitem(a) (NULL)
#define eq(a,b) (a==b) /*equality between keys */
#define hash(a, b) (a%b) /*hash function*/

/*Function Declaration/Prototype*/
void STinit(int m);
void expand();
void STinsert(Item item);
Item STdelete(Item item);
Item STsearch(Key v);

#endif
