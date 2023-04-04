#include <stdio.h>
#include <stdlib.h>

int fatorial(int v){
    if(v==0) return 1;
    else return v * fatorial(v-1);
}
int fibonacci(int i){
    if(i==1) return 0;
    else if(i==2) return 1;
    else return fibonacci(i-1) + fibonacci(i-2);
}

int main(void){

    int x = 10;
    printf("fatorial de %d = %d\n", x, fatorial(x));
    printf("%d° elemento da seq Fibonacci é: %d", x, fibonacci(x));
}