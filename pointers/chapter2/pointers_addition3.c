#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a;
  int *pa = &a;
  char c;
  char *pc = &c;
  printf("posição pa = %p\n", pa);
  printf("posição pa +1 = %p\n", pa +1);
  printf("posição pc = %p\n", pc);
  printf("posição pc +1 = %p\n", pc +1);
  return EXIT_SUCCESS;
}