#include <stdio.h>
#include <stdlib.h>

int main()
{
   double valores [] = {10.5, 9.88, 7.78,6.51};
   double * p0 = valores;
   double * p1 = valores +1;
   double * p2 = valores + 2;
   printf("p1 - p0 = %d\n", p1 - p0);
   printf("p2 - p1 = %d\n", p2 - p1);
   printf("p2 - p0 = %d\n", p2 - p0);
   printf("p0 - p2 = %d\n", p0 - p2);
   return EXIT_SUCCESS;
}