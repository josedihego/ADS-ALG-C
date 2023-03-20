#include <stdio.h>
#include <stdlib.h>

int main2(void)
{
    
  int x;
  printf("%s","Digite o mes\n");
  
  scanf("%d",&x);
  
  switch(x)
  {
     case 1: 
          printf("%s","janeiro ou marco\n");
     case 2:
          printf("%s","fevereiro\n");
          break;
     case 12:
          printf("%s","dezembro\n");
          break;     
     default:
         printf("%s","Vc digitou um mes diferente de 1,2 ou 12\n");         
  }
        
  
  //if(x==1) {
//  printf("%s","janeiro\n");
//  }
//  else{
//       if(x==2) 
//         {
//                printf("%s","fevereiro\n");
//         }
//       else{
//            if(x==12) 
//            {
//                      printf("%s","dezembro\n");
//            }
//            else
//            {
//                printf("%s","Vc digitou um mes diferente de 1,2 ou 12\n");         
//            }
//       }        
//  }
   
  system("PAUSE");	
  return 0;
}
