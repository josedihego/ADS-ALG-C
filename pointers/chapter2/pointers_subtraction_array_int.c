#include <stdio.h>
#include <stdlib.h>

int main()
{
   int idades [] = {10, 9, 7,6};
   int i= 3;
   int * pn  = idades+i;
   printf("idades[%d]: %d\n",i, *pn);
   pn = pn -1;
   i = i -1;
   printf("idades[%d]: %d\n",i, *pn);
   return EXIT_SUCCESS;
}