#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// Fatorial

int factorial(int x){
    int res = 1;
    for(int i=1; i <= x; i = i +1){
        res = res * i;
    }
    return res;
}

int main(){
    int x;
    printf("Informe o valor de x:");
    scanf("%d",&x);
    printf("O fatorial de %d : %d\n", x, factorial(x));
}