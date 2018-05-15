#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test2.h"

int main(){
  link head = NULL;
  Item test = (Item) malloc(6*sizeof(Item*));
  strcpy(test,"TESTE");
  head = insertBegin(head, test);
  head = insertBegin(head, "a");
  head = insertBegin(head, "b");
  printList(head);
  return 0;
}


task1.id = 123;
strcpy(task1.description, "ola tudo bem");
task1.duration = 23;
link node1 = newNode(task1, NULL); /*Allocs memory*/
addNode(a,node1);
task2.id = 456;
strcpy(task2.description, "sup");
task2.duration = 114;
link node2 = newNode(task2, NULL); /*Allocs memory*/
addNode(a,node2);
task3.id = 90240525245;
strcpy(task3.description, "ehehehehehehhehehe");
task3.duration = 242424121446426;
link node3 = newNode(task3, NULL); /*Allocs memory*/
addNode(a,node3);
printList(a);
removeNode(a, node3);
link node4 = newNode(task2, NULL); /*Allocs memory*/
addNode(a,node4);
printList(a);
free(node1);
free(node2);
free(node4);
