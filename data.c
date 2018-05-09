/************
*************
May 8th '18

All Rights Reserved © Daniel Lopes

File: data.c
Project: Tasks management
*************
Description:
This auxiliary file contains all the implementations
of the functions in the data structure of type list
*************/

link insertBegin(link head, int a)
{
link new = (link)malloc(sizeof(struct node));
new->value = a;
new->next = head;
return new;
}

link insertEnd(link head, int value)
{
 link t;
 link new = (link)malloc(sizeof(struct node));
 new->value = value;
 new->next = NULL;
 if(head == NULL) return new;
 for(t = head; t->next != NULL; t = t->next)
;
 t->next = new;
 return head;
}

void printList(link head)
{
 link t;
 for(t = head; t != NULL; t = t->next)
 printf(“%d\n”,t->value);
}
