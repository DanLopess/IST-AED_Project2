#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test2.h"

link insertBegin(link head, Item a)
{
  link new = (link)malloc(sizeof(struct node));
  new->value = a;
  new->next = head;
  return new;
}

link insertEnd(link head, Item value)
{
 link t;
 link new = (link) malloc(sizeof(struct node));
 new->value = value;
 new->next = NULL;
 if(head == NULL) return new;
 for(t = head; t->next != NULL; t = t->next);
 t->next = new;
 return head;
}

void printList(link head)
{
 link t;
 for(t = head; t != NULL; t = t->next)
 printf("%s\n",t->value);
}
