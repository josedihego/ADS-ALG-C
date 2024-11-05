#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int potencia(int x, int y){
    if(y==0) return 1;
    if(y==1) return x;
    int res = 1;
    for(int i = 0; i < y; i =i+1){
        res = res * x;
    }
    return res;
}

bool testar_primo(int n){
   int qnt = 0;
   for(int i = 1; i <= n; i = i +1){
       if(n%i==0) qnt = qnt +1;
   }
   if (qnt==2) return true;
   else return false;
}


int main(){
   int qnt_num_mer = 20;
   int qnt_encontrados = 0;
   int n = 2;
   while(qnt_encontrados < qnt_num_mer){
        bool n_primo = testar_primo(n);
        int mersenne_n = potencia(2,n)-1;
        bool mersenne_n_primo = testar_primo(mersenne_n);
        if(n_primo && mersenne_n_primo){
            printf("Achei mais uma :) (%d, %d)\n",n,mersenne_n);
            qnt_encontrados = qnt_encontrados +1;
        }
        n =  n +1;

   }
}