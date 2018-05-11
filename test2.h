#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
 char* value;
 struct node *next;
} *link;

typedef char* Item;

link insertBegin(link head, Item a);
link insertEnd(link head, Item value);
void printList(link head);
