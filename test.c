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
