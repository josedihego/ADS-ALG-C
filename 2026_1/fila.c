#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Cliente{
    char * CPF;
    char * nome;
    struct Cliente * anterior;
}Cliente;

typedef struct Fila{
    Cliente * primeiro;
    Cliente * ultimo;
}Fila;

Cliente * criar_cliente(char * CPF, char * nome){
    printf("criar\n");
    printf("%s %s \n",CPF, nome);
    Cliente * novo = (Cliente *) malloc(sizeof(Cliente));
    printf("passou malloc");
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
    printf("tamanho de um cliente %ld bytes\n", sizeof(Cliente *));
}