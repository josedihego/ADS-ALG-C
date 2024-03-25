#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
int main(void)
{
  int i;  
  List * L = malloc(sizeof(List));
  Node * n;
  init(L);
  
  for(i=0;i <= 5; i++)
  {
   n = malloc(sizeof(Node));
   n->data = i;
   insertL(L,n);        
  }
  printL(L);
  
  n= searchL(L,5);
  removeL(L,n);
  printL(L);
  
  n= searchL(L,0);
  removeL(L,n);
  printL(L);
  
  n= searchL(L,3);
  removeL(L,n);
  printL(L);
  
  n = searchL(L,90);
  if(n==NULL) printf("%s","Elemento nao encontrado\n");
  
  system("PAUSE");	
  return 0;
}
