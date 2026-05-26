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

Cliente * criar_cliente(const char * CPF, const char * nome){
    Cliente * novo = malloc(sizeof(Cliente));
    novo->nome = malloc(MAX * sizeof(char));
    novo->CPF = malloc(MAX * sizeof(char));
    strcpy(novo->CPF, CPF);
    strcpy(novo->nome, nome);
    novo->anterior = NULL;
    return novo;
}

void imprimir_cliente(Cliente * cliente){
    printf("imprimir\n");
    if(cliente!=NULL){
        printf("----- Dados do cliente ----\n");
        printf("\t Nome: %s\n", cliente->nome);
        printf("\t CPF: %s\n", cliente->CPF);
    }
    else{
        printf("Cliente inválido. [NULL]");
    }

}

int main(){
   
    Cliente * maria = criar_cliente("111.222.333-44", "Maria");
    imprimir_cliente(maria);
    printf("tamanho de um ponteiro para cliente %ld bytes\n", sizeof(Cliente *));
    printf("tamanho de um cliente %ld bytes\n", sizeof(Cliente ));
}