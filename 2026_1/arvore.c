#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

typedef struct Cliente
{
    char *CPF;
    char *nome;
} Cliente;

typedef struct Payload
{
    Cliente *cliente;
    // o que mais você quisesse
} Payload;

typedef struct No
{
    int chave;
    Payload *payload;
    struct No *esq;
    struct No *dir;
    struct No *mae;
} No;

typedef struct Arvore
{
    No *raiz;
} Arvore;

No *criar_no(int chave)
{
    No *novo = malloc(sizeof(No));
    novo->chave = chave;
    novo->dir = novo->esq = novo->mae = NULL;
    return novo;
}

Arvore *criar_arvore()
{
    Arvore *nova = malloc(sizeof(Arvore));
    nova->raiz = NULL;
    return nova;
}

No *buscar_no(int chave, Arvore *arvore)
{
    No *x = arvore->raiz;
    while (x != NULL && x->chave != chave)
    {
        if (chave < x->chave)
        {
            x = x->esq;
        }
        else
        {
            x = x->dir;
        }
    }
    return x;
}

void inserir_no(No *novo, Arvore *arvore)
{
    if (arvore->raiz == NULL)
    {
        arvore->raiz = novo;
    }
    else
    {
        No *c3po = arvore->raiz;
        No *luke_skywalker = c3po;
        while (c3po != NULL)
        {
            luke_skywalker = c3po;
            if (novo->chave < c3po->chave)
            {
                c3po = c3po->esq;
            }
            else
            {
                c3po = c3po->dir;
            }
        }
        if (novo->chave < luke_skywalker->chave)
        {
            luke_skywalker->esq = novo;
        }
        else
        {
            luke_skywalker->dir = novo;
        }
        novo->mae = luke_skywalker;
    }
}

void imprimir_arvore( No * no, int i){
    if(no!=NULL){
        imprimir_arvore(no->esq, i+1);
        printf(" (%d) \n",no->chave);
        imprimir_arvore(no->dir, i+1);
    }
}

void remover_no_arvore(Arvore * arvore, No * no){

}

No * minimo_arvore(No * x){
    No * y = x;
    while(y!=NULL && y->esq!=NULL){
        y=y->esq;
    }
    return y;
}

// nesse caso sabemos que X tem dois filhos
// essa função é parcial
No * sucessor_arvore(No * x){
    assert(x->dir!=NULL);
    //No * y = x->dir;
    return minimo(x->dir);// y

}

void remover_no_arvore_chave(Arvore * arvore, int chave){
    No * no = buscar_no(chave,arvore);
    if(no!=NULL){
         //caso 3: com dois filhos
         if(no->esq!=NULL && no->dir!=NULL){
            No * sucessor = sucessor_arvore(no);
            int chave_sucessor = sucessor->chave;
            remover_no_arvore_chave(arvore, chave_sucessor);
            no->chave = chave_sucessor;
            //aqui você copiaria também dados satélites

         }
        //caso 1: folha, sem filhos
        else if(no->esq== NULL && no->dir==NULL){
            No * mae = no->mae;
            if(no->chave > mae->chave){
                mae->dir = NULL;
            }
            else{
                mae->esq = NULL;
            }
            free(no);
        }
        //caso 2: com apenas um filho
        //No * mae = 
        else{
            No * filho = no->esq!=NULL? no->esq : no->dir;
            No * mae = no->mae;
            // no removido esta a direita de sua mãe
            if(no->chave > mae->chave){
                mae->dir = filho;
            }
            // no removido esta a esquerda de sua mãe 
            else{
                mae->esq = filho;
            }
            filho->mae = mae;
            free(no);

        }
       
    }
}

#define TAM 20

int main()
{
    srand(time(NULL));
    Arvore * arvore = criar_arvore();
    for(int i = 0; i < TAM; i = i +1){
        int chave = rand()%100;
        inserir_no(criar_no(chave),arvore);
    }
    imprimir_arvore(arvore->raiz,0);

    return EXIT_SUCCESS;
}