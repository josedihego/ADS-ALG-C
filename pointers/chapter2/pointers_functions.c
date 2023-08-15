#include<stdio.h>
#include<stdlib.h>

int soma(int a, int b){
 return a+b;
}

int main(){
    int (*pf) (int,int);
    pf = &soma;
    int res = pf(5,7);
    printf("soma(5,7) = %d\n", res);
    return EXIT_SUCCESS;
}