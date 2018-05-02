#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void add();
void duration();
void depend();
void removes();
void path();
void exit();


int main(){
  char *command;
  int size = 20;
  command = (char*) malloc(sizeof(char)*size);
  fgets(command,sizeof(char)*size,stdin);
  printf("%s", command);
  /*free(command);*/
  return 0;
}
