#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

typedef struct Cliente{
    char * CPF;
    char * nome;
    struct Cliente * anterior;
}Cliente;

typedef struct Fila{
    Cliente * primeiro;
    Cliente * ultimo;
}Fila;

Fila * criar_fila(){
    Fila * nova =  malloc(sizeof(Fila));
    nova->primeiro = NULL;
    nova->ultimo = NULL;
    return nova;
}

Cliente * criar_cliente(const char * CPF, const char * nome){
    Cliente * novo = malloc(sizeof(Cliente));
    novo->nome = malloc(MAX * sizeof(char));
    novo->CPF = malloc(MAX * sizeof(char));
    strcpy(novo->CPF, CPF);
    strcpy(novo->nome, nome);
    novo->anterior = NULL;
    return novo;
}

void adicionar_fila(Fila * fila, Cliente * novo){
    if(fila->primeiro==NULL){
        fila->primeiro = novo;
        fila->ultimo = novo;
    }
    else{
        fila->ultimo->anterior = novo;
        fila->ultimo = novo;
    }
}

Cliente * remover_fila(Fila * fila){
    Cliente * primeiro = fila->primeiro;
    if(primeiro!=NULL){
        fila->primeiro = primeiro->anterior;
        //TODO: verificar situação em que lista so tem um elemento
    }
    else{
        printf("Fila vazia\n");
    }
    return primeiro;
}

void imprimir_cliente(Cliente * cliente){
    if(cliente!=NULL){
        printf("----- Dados do cliente ----\n");
        printf("\t Nome: %s\n", cliente->nome);
        printf("\t CPF: %s\n", cliente->CPF);
    }
    else{
        printf("Cliente inválido. [NULL]");
    }
}

void imprimir_fila(Fila * fila){
    printf("Início da impressão da fila:\n");
    for(Cliente * c = fila->primeiro; c!=NULL; c= c->anterior){
        imprimir_cliente(c);
    }
}

int main(){
   
    /*
    Cliente * maria = criar_cliente("111.222.333-44", "Maria");
    imprimir_cliente(maria);
    printf("tamanho de um ponteiro para cliente %ld bytes\n", sizeof(Cliente *));
    printf("tamanho de um cliente %ld bytes\n", sizeof(Cliente ));
    */

    Fila * fila_banco = criar_fila();
    adicionar_fila(fila_banco, criar_cliente("111.111.111-11","Maria"));
    adicionar_fila(fila_banco, criar_cliente("222.111.111-11","Luana"));
    adicionar_fila(fila_banco, criar_cliente("333.111.111-11","Jô"));
    adicionar_fila(fila_banco, criar_cliente("444.111.111-11","Boiste"));
    adicionar_fila(fila_banco, criar_cliente("555.111.111-11","Carlos"));
    remover_fila(fila_banco);
    imprimir_fila(fila_banco);


    fila_banco = criar_fila();
    adicionar_fila(fila_banco, criar_cliente("111.111.111-11","Maria"));
    remover_fila(fila_banco);
     imprimir_fila(fila_banco);

}