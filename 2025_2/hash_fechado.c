#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define TAM 50

typedef struct no{
    int chave;
    no * prox;
}no;

typedef struct lista_ligada{
    no * inicio;
    no * fim;
}lista_ligada;

typedef struct hash_fechada{
    lista_ligada ** T;
    int tam;
}hash_fechada;

lista_ligada * criar_lista(){
    lista_ligada * nova = malloc(sizeof(lista_ligada));
    nova->fim = NULL;
    nova->inicio = NULL;
    return nova;
}

no * criar_no(int chave){
    no * novo = malloc(sizeof(no));
    novo->chave = chave;
    novo->prox = NULL;
}

hash_fechada * criar_hash(int tamanho){
    hash_fechada * nova = malloc(sizeof(hash_fechada));
    nova->tam = tamanho;
    nova->T = malloc(tamanho * sizeof(lista_ligada *));
    for(int i = 0; i <tamanho; i = i +1){
        nova->T[i] = NULL;
    }
}

int h (int chave){
    return ((int)((chave * 37 * sqrt(5)))) % TAM;
}

void inserir_lista(lista_ligada * lista, int chave){
     no * novo = criar_no(chave);
    if(lista->inicio==NULL && lista->fim==NULL){
            lista->inicio = novo;
            lista->fim = novo;
    }
    else{
        lista->fim->prox = novo;
        lista->fim = novo;
    }
}

void inserir_hash(hash_fechada * hash, int chave){
    int posicao = h(chave);
    if(hash->T[posicao]==NULL){
        hash->T[posicao] = criar_lista();
    }
    inserir_lista(hash->T[posicao], chave);

}
