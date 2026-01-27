#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int chave;
    struct no * esq;
    struct no * dir;
    struct no * mae;
}no;

typedef struct Arvore{
    no * raiz;
}Arvore;

no * criar_no(int chave){
    no * novo = malloc(sizeof(no));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->mae = NULL;
    return novo;
}

void rotacionar_direita(Arvore * T, no * x){
    no * y = x->esq;
    x->esq = y->dir;
    y->dir->mae = x;

    y->mae = x->mae;
    if(x->mae == NULL){
        T->raiz = y;
    }
    else{
        if(x== x->mae->esq){
            x->mae->esq = y;
        }
        else{
            x->mae->dir = y;
        }
    }
    y->dir = x;
    x->mae = y;
}

void inserir_no(no * novo, Arvore * arvore){
    if(arvore->raiz==NULL){
        arvore->raiz = novo;
    }
    no * sisu = arvore->raiz;
    no * mae = arvore->raiz;
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

void remover_no(int chave, Arvore * arvore){
    no * marcado = arvore->raiz;
    while(marcado!=NULL && marcado->chave != chave){
        if(chave > marcado->chave){
            marcado = marcado->dir;
        }
        else{
            marcado = marcado->esq;
        }
    }
    if(marcado!=NULL){
        //caso 1
        if(marcado->esq==NULL && marcado->dir==NULL){
            if(marcado->chave > marcado->mae->chave){
                marcado->mae->dir = NULL;
            }
            else{
                marcado->mae->esq = NULL;
            }
            free(marcado);
        }
        //caso 2
        else if(marcado->esq==NULL || marcado->dir==NULL){
            
        }

        //caso 3
    }
}

int main(){
    no * n1 = malloc(sizeof(no));
    n1->chave = 1;
    n1->dir = NULL;
    n1->esq = NULL;
    n1->mae = NULL;
    //inserir_no(n1, arvore);
}