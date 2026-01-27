#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

#define TAM 10

typedef struct tabela_hash{
    int * valores;
    int tamanho;
}tabela_hash;

tabela_hash * criar_tabela(){
    tabela_hash * tabela  = malloc(sizeof(tabela_hash));
    tabela->valores = malloc(TAM * sizeof(int));
    tabela->tamanho = TAM;
    for(int i = 0; i < TAM; i = i +1){
        tabela->valores[i] = -1;
    }
    return tabela;
}

int h(int elemento, int i){
    return ((int)(elemento *37 * sqrt(5) * (i+1))) % TAM;
}

void inserir(tabela_hash * tabela, int elemento){
    int i = 0;
    int p = h(elemento, 0);
    if(tabela->valores[p]==-1){
        tabela->valores[p] = elemento;
    }
    else{
        p = h(elemento, i);
        while(tabela->valores[p]!=-1 && i < TAM){
            i = i +1;
            p = h(elemento, i);
        }
        if(i < TAM){
          tabela->valores[p] = elemento;
        }
    }
}

void imprimir (tabela_hash * tabela){
    printf(" Conteúdo da hash table: \n \t ");
    for(int i = 0; i < tabela->tamanho; i = i +1){
        printf("[%d] = %d ", i, tabela->valores[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    tabela_hash * tabela = criar_tabela();
    for(int i = 0; i < 20; i = i +1){
        int x = rand() % 100;
        printf("%d ", x);
        inserir(tabela, x);
    }
    imprimir(tabela);
    //int x = 34;
    //printf("posicao de %d é %d\n", x, h(x,2));
}
