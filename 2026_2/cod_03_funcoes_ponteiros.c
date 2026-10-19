#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

// fatorial
int calc_fatorial(int numero){
    int resultado = 1;
    for(int i = numero; i >1; i = i-1){
        resultado = resultado * i;
    }
    return resultado;
}

int calc_fat_rec(int numero){
    if(numero<=1) return 1;
    else return numero * calc_fat_rec(numero-1);
}
// primo

bool eh_primo(int numero){
    bool primo = true;
    int d = 2;
    while(primo && d <numero/2){
        if(numero%d==0){
            primo = false;
        }
        d = d+1;
    }
    return primo;
}

int main(){
    double x = sqrt(10);
    printf("%f\n",x);
    srand(time(NULL));
    int valor = rand()%15;
    int r = calc_fatorial(valor);
    printf("fatorial de %d é %d\n",valor,r);
    int numero = rand();
    printf("%d é primo? %s\n",numero, eh_primo(numero)? "Sim": "Não");
    return EXIT_SUCCESS;
}
// se um número é primo