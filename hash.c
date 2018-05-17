/*NOTES:
- Implementar por procura linear
- Quando introduzo um Item na lista simplesmente ligada,
introduzo um ponteiro para o elemento na hash table
*/

#include <stdlib.h>

typedef struct person {
	char*name;
	unsigned long int idNumber;
}*pPerson; /* pPerson é um pointer para uma struct person */

static int M; /* tamanho da minha tabela */
static pPerson *st; /* a minha tabela de pointers */

void Stinit(int m) {
	int i; M=m;
	st = (pPerson*)malloc(M*sizeof(pPerson));
	for (i = 0; i < M; i++)
		st[i] = NULL; /* inicializo tudo a NULL */
}
void STinsert(pPerson p) {
	int i = hash(p->idNumber, M);
	while (st[i]!=NULL) i = (i+1) % M;
	st[i] = p;
}

void expand();
void STinsert(Item item) {
 Key v = key(item);
 int i = hash(v, M);
 while (st[i]!=NULLitem)
 i = (i+1) % M;
 st[i] = item;
 if (N++ > M/2)
 expand();
}
void expand() {
 int i;
 Item *t = st;
 init(M+M);
 for (i = 0; i < M/2; i++)
 if (key(t[i]) != NULLitem)
 STinsert(t[i]);
 free(t);
}
