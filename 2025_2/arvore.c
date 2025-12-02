#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int chave;
    struct No * esq;
    struct No * dir;
    struct No * mae;
}No;

typedef struct Arvore{
    No * raiz;
}Arvore;

void inserir_no(No * novo, Arvore * arvore){
    if(arvore->raiz==NULL){
        arvore->raiz = novo;
    }
    No * sisu = arvore->raiz;
    No * mae = arvore->raiz;
    while(sisu!=NULL){
        mae = sisu;
        if(novo->chave > sisu->chave){
            sisu  = sisu->dir;
        }
        else{
            sisu = sisu->esq;
        }
    }
    novo->mae = mae;
    if(novo->chave > mae->chave){
        mae->dir = novo;
    }
    else{
        mae->esq = novo;
    }
}

int main(){
    No * n1 = malloc(sizeof(No));
    n1->chave = 1;
    n1->dir = NULL;
    n1->esq = NULL;
    n1->mae = NULL;
    //inserir_no(n1, arvore);
}