#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50
typedef struct Cliente{
    char * nome;
    struct Cliente * anterior;

}Cliente;

Cliente * criar_cliente(const char * nome){
    printf("criar inicio\n");
    Cliente * novo = malloc(sizeof(Cliente));
    novo->nome = malloc(MAX * sizeof(char));
    strcpy(novo->nome, nome);
    novo->anterior = NULL;
    printf("criar fim\n");

    return novo;
}


int main(){
    Cliente * maria = criar_cliente("Maria");
    printf("tamanho de um cliente %ld bytes\n", sizeof(Cliente *));
}