#include <stdio.h>
#include <stdlib.h>

int main()
{
   char * nomes [] = {"maria", "maza", "cotovelo", "cracati"};
   int i= 3;
   char ** pn  = nomes+i;
   printf("nomes[%d]: %s\n",i, *pn);
   pn = pn -1;
   i = i -1;
   printf("nomes[%d]: %s\n",i, *pn);
   return EXIT_SUCCESS;
}