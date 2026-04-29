#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pilha{
    int * valores;
    int tam;
    int topo;
}Pilha;

Pilha * criar_pilha(int tam){
    Pilha * nova_pilha = malloc(sizeof(Pilha));
    nova_pilha->valores  = malloc(tam * sizeof(int));
    nova_pilha->tam = tam;
    nova_pilha->topo = 0;
    return nova_pilha;
}

bool esta_cheia(Pilha * pilha){
    return pilha->topo == pilha->tam-1;
}
bool esta_vazia(Pilha * pilha){
    return pilha->topo == 0;
}
bool empurrar(Pilha * pilha, int novo){
    bool sucesso = true;
    if(!esta_cheia(pilha)){
        pilha->valores[pilha->topo] = novo;
        pilha->topo = pilha->topo + 1;
    }
    else{
        sucesso = false;
        printf("A pilha esta cheia\n");
    }
    return sucesso;
}

bool estourar(Pilha * pilha){
    bool sucesso = true;
    if(!esta_vazia(pilha)){
        pilha->topo = pilha->topo - 1;
    }
    else{
        sucesso = false;
        printf("Pilha vazia\n");
    }
    return sucesso;
}
