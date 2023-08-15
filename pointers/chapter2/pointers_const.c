#include <stdio.h>
#include <stdlib.h>


int main()
{
  int num = 7;
  const int * p_num = &num;
  printf("num = %d \n", *p_num);
  // ERRO de compilação
  //*p_num = 70;
  printf("num alterado? = %d \n", *p_num);

}