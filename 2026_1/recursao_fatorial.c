#include <stdio.h>
#include <stdlib.h>

#define N 5
#define FIB 50
int fatorial(int n){
    if(n==0 || n==1) return 1;
    else return n * fatorial(n-1);
}

int fibonacci(int enesimo, int * passos){
    // exato ponto eu tivesse algo para fazer ++
    *passos = *passos +1;
    if(enesimo==1) return 0;
    if(enesimo==2) return 1;
    return fibonacci(enesimo-1,passos) + fibonacci(enesimo-2,passos);
}

int main(){
    int passos = 0;
    int res = fatorial(N);
    printf("fatorial(%d)= %d \n",N, res);
    res = fibonacci(FIB, &passos);
    printf("fibonacci(%d) = %d  em %d passos\n", FIB, res,passos);
}