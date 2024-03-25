#include <stdio.h>
#include<stdlib.h>

typedef struct 
{
   double a;
   int b;
}X;

typedef struct 
{
   int c;
   int b;
   double a;  
}Y;


typedef struct 
{
   char * nome, *cpf;
   int idade;
}funcionario;

int main(){
    funcionario f;
    funcionario *pf;
    size_t tam_f = sizeof(f);
    size_t tam_pf = sizeof(pf);
    printf("size funcionario: %zu\n", tam_f);
    printf("size funcionario *: %zu\n", tam_pf);


    X x;
    X *xf;
    size_t tam_x = sizeof(x);
    size_t tam_xf = sizeof(xf);
    printf("size X: %zu\n", tam_x);
    printf("size X *: %zu\n", tam_xf);


    Y y;
    Y *yf;
    size_t tam_y = sizeof(y);
    size_t tam_yf = sizeof(yf);
    printf("size Y: %zu\n", tam_y);
    printf("size Y *: %zu\n", tam_yf);


    return EXIT_SUCCESS;
}
