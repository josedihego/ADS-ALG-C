#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
  int x;
  printf("%s","Digite o mes: ");
  
  scanf("%d",&x);
  
  switch(x)
  {
     case 1: 
          printf("%s","janeiro\n");
     case 2:
          printf("%s","fevereiro\n");
          break;
     case 12:
          printf("%s","dezembro\n");
          break;     
     default:
         printf("%s","Você não digitou 1,2 ou 12 \n");         
  }
        
  return 0;
}
