#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include<stdbool.h>
#include <assert.h>

typedef struct No{
    int chave;
    struct No * prox;
    struct No * ant;
}No;

typedef struct Lista{
    No * cabeca;
}Lista;


No * criar_no(int chave){
    No * novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->ant = NULL;
    novo->prox = NULL;
}

void inserir(Lista * l, No * novo){
    if(l->cabeca==NULL){
        l->cabeca = novo;
    }
    else{
        novo->prox = l->cabeca;
        l->cabeca->ant = novo;
        l->cabeca = novo;
        //Kaylan
        //novo->ant = l->cabeca;
        //novo->prox = l->cabeca->prox;
    }
}

No * buscar(Lista * l, int chave){
    No * x = l->cabeca;
    while(x!=NULL && x->chave != chave){
        x = x->prox;
    }
    return x;
} 

void remover(Lista * l, No * r){
    assert(r!=NULL);
    if(r!=NULL){
        if(r->ant ==NULL){
            l->cabeca = r->prox;
            if(l->cabeca!=NULL) l->cabeca->ant = NULL;
        }
        else if(r->prox==NULL){
            r->ant->prox = NULL;
        }
        else{
            r->ant->prox = r->prox;
            r->prox->ant = r->ant;
        }
        free(r);
    }
}

void imprimir_no(No * x){
    if(x!=NULL){
        printf("<-%d->",x->chave);
    }
}

void imprimir(Lista * l){
    No * x = l->cabeca;
    while(x!=NULL){
        imprimir_no(x);
         x = x->prox;
    }
}

int main(){
    printf("Size of No é %lu\n",sizeof(No));
    Lista * nos_legais = malloc(sizeof(Lista));
    inserir(nos_legais,criar_no(5));
    inserir(nos_legais,criar_no(8));
    inserir(nos_legais,criar_no(9));
    inserir(nos_legais,criar_no(15));
    printf("\n");
    imprimir(nos_legais);
    printf("\n");
}