#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"

extern int MAX;

int main(int argc, char *argv[])
{
  Stack *s = (Stack *)malloc(sizeof(Stack));
  init(s);
  printStack(s);
  push(s, 1);
  push(s, 2);
  push(s, 3);
  printStack(s);
  pop(s);
  pop(s);
  printStack(s);
  push(s, 2);
  push(s, 3);
  printStack(s);
  push(s, 4);
  printStack(s);
  pop(s);
  pop(s);
  pop(s);
  printStack(s);
  pop(s);
  return 0;
}
