// Árvore binária de busca
#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int chave;
    struct No * esq;
    struct No * dir;
    struct No * mae;
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
}

void inserir(Arvore * a, No * x){
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
}

int main(){
    Arvore * arvore = malloc(sizeof(Arvore));
    inserir(arvore, criar_no(9));
    inserir(arvore, criar_no(10));
    inserir(arvore, criar_no(8));
    printf("Fim");   
}