#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct elemento{
    int chave;
}elemento;

typedef struct tabela_hash_aberta{
    elemento ** valores;
    int tamanho;
}tabela_hash_aberta;

elemento * criar_elemento(int chave){
    elemento * e = malloc(sizeof(elemento));
    e->chave = chave;
    return e;
}

void preencher_null(elemento ** valores, int tamanho){
    for(int i = 0; i < tamanho; i = i +1){
        valores[i] = NULL;
    }
}

tabela_hash_aberta * criar(int tamanho){
    tabela_hash_aberta * tabela = malloc(sizeof(tabela_hash_aberta));
    tabela->tamanho =  tamanho;
    tabela->valores = malloc(sizeof(elemento *) * tamanho);
    preencher_null(tabela->valores, tamanho);
    return tabela; 
}

int h(int chave, int i, int m){
    float knuth = (sqrt(5)-1)/2;
    return ((int)(floor( m * chave * knuth))) % m;
}

bool adicionar_aberto(elemento * elemento, tabela_hash_aberta * tabela){
    bool inserido = false;
    int i = 0;
    do{
        int posicao = h(elemento->chave,i, tabela->tamanho);
        if(tabela->valores[posicao]==NULL){
            tabela->valores[posicao] = elemento;
            inserido = true;
        }
        else{
            i = i +1;
        }

    }
    while(i < tabela->tamanho && !inserido);
    return inserido;
}

void imprimir_hash(tabela_hash_aberta * hash){
    for(int p = 0; p < hash->tamanho; p = p+1){
        if(hash->valores[p]==NULL){
            printf("NULL\n");
        }
        else{
            printf("%d tem %d\n", p, hash->valores[p]->chave);
        }
    }
}

int main(){
   tabela_hash_aberta * tabela = criar(10);
   adicionar_aberto(criar_elemento(15), tabela);
   adicionar_aberto(criar_elemento(34), tabela);
   imprimir_hash(tabela);


}