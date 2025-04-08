#include<stdio.h>
#include<stdlib.h>

int main(){
    int * valores;
    int A = 10;
    printf("A=%d\n", A);
    valores = &A;
    printf("A=%d\n",A);
    A = 30;
    printf("A = %d\n", A);
    printf("*valores = %d\n", *valores);
    printf("endereço de valores: %p\n",valores);
    *valores = 80;
    printf("A=%d\n",A);
}