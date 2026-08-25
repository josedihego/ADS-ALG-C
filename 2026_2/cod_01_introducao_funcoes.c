#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int soma(int op1, int op2){
    return op1+op2;
}

int maior_entre_dois(int x, int y){
    if(x > y) return x;
    else return y;
}

int main(){
    int v1 = 20;
    int v2 = 30;
    int v3 = 80;
    int v4 = 90;
    int res = soma(v1,v2);
    printf("%d+%d=%d\n",v1,v2,res);
    printf("80+90=%d\n",soma(80,90));
    printf("maior entre %d e %d é %d\n", v1,v2, maior_entre_dois(v1,v2));
    int soma_maiores = soma(maior_entre_dois(v1,v2), maior_entre_dois(v3,v4));
    printf("Soma entre maiores pares (%d,%d) e (%d,%d) é %d\n", v1,v2,v3,v4, soma_maiores);
}