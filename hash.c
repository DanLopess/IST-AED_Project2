/*NOTES:
- Implementar por procura linear
- Quando introduzo um Item na lista simplesmente ligada,
introduzo um ponteiro para o elemento na hash table
*/

#include <stdlib.h>
#include "hash.h"
#include "list.h"

static link *heads;
static int M;

int hash(Key value, int m){
	return value % m;
}

void STinit(int m) {
 int i;
 M = m;
 heads = (link*)malloc(M*sizeof(link));
 for (i = 0; i < M; i++) 
 	heads[i] = NULL;
}

void STinsert(void* item) {
 int i = hash(key(item), M);
 heads[i] = insertBeginList(heads[i], item);
}

void STdelete(void* item) {
 int i = hash(key(item), M);
 heads[i] = removeItemList(heads[i], item);
}

Item STsearch(Key v) {
 int i = hash(v, M);
 return searchList(heads[i], v);
}
