#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int fatorial(int n){
    int resultado = 1;
    for(int i = 1; i <=n; i = i +1){
        resultado = resultado * i;
    }
    return resultado;
}

int fat(int n){
    if(n==1) return 1;
    else return n * fat(n-1);
}

int fibonacci(int p){
    if(p <= 2) return 1;
    else return fibonacci(p-1) + fibonacci(p-2);
}

int main(){
    int valor;
    printf("Informe um valor: ");
    scanf("%d",&valor);
    /**
    int r = fatorial(valor);
    printf("fatorial(%d) = %d\n", valor, r);
    r = fat(valor);
    printf("recursivo fat(%d) = %d\n", valor,r);
  */
   int f = fibonacci(valor);
   printf("fibonacci(%d) =  %d\n",valor,f);

}