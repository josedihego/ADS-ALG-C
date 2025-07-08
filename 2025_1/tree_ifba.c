// Árvore binária de busca
#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int chave;
    struct No * esq;
    struct No * dir;
    struct No * mae;
    int balanco;
}No;

typedef struct Arvore{
    No * raiz;
}Arvore;

No * criar_no(int chave){
    No * novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->mae = NULL;
    novo->balanco = 0;
}

void inserir(Arvore * a, No * x){
    // passo 1. Atualizar o balanço
    if(a->raiz == NULL){
        a->raiz = x;
    }
    else{
        No * mae = a->raiz;
        No * robo = a->raiz;
        while(robo != NULL){
            mae = robo;
            if(x->chave > robo->chave){
                robo= robo->dir;
            }
            else{
                robo = robo->esq;
            }
        }
        if(x->chave > mae->chave){
            mae->dir = x;
        }
        else{
            mae->esq = x;
        }
        x->mae = mae;
    }
    //voltar usando o ponteiro mae
    // até a raiz, se nessa volta
    // voçê achar um balance de 2
    // faça a rotação apropriada
    // D, E, D->E, E->D
}

void rotacao_direita(Arvore * T, No * x){
    No * y = x->esq;
    x->esq = y->dir;
    if(y->dir != NULL){
        y->dir->mae = x;
    }
    y->mae = x->mae;
    if(x->mae == NULL){
        T->raiz = y;
    }
    else{
        if(x == x->mae->esq){
            x->mae->esq = y;
        }
        else{
            x->mae->dir = y;
        }
    }
    y->dir = y;
    x->mae  = y;

}

int main(){
    Arvore * arvore = malloc(sizeof(Arvore));
    inserir(arvore, criar_no(9));
    inserir(arvore, criar_no(10));
    inserir(arvore, criar_no(8));
    printf("Fim");   
}