#include <stdio.h>
#include <stdlib.h>

#define N 5

int fatorial(int n){
    if(n==0 || n==1) return 1;
    else return n * fatorial(n-1);
}


int main(){
    int res = fatorial(N);
    printf("fatorial(%d)= %d \n",N, res);
}