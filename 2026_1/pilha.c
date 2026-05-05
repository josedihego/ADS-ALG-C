#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pilha
{
    int *valores;
    int tam;
    int topo;
} Pilha;

Pilha *criar_pilha(int tam)
{
    Pilha *nova_pilha = malloc(sizeof(Pilha));
    nova_pilha->valores = malloc(tam * sizeof(int));
    nova_pilha->tam = tam;
    nova_pilha->topo = 0;
    return nova_pilha;
}

bool esta_cheia(Pilha *pilha)
{
    return pilha->topo == pilha->tam;
}
bool esta_vazia(Pilha *pilha)
{
    return pilha->topo == 0;
}
bool empurrar(Pilha *pilha, int novo)
{
    bool sucesso = true;
    if (!esta_cheia(pilha))
    {
        pilha->valores[pilha->topo] = novo;
        pilha->topo = pilha->topo + 1;
    }
    else
    {
        sucesso = false;
        printf("A pilha esta cheia\n");
    }
    return sucesso;
}

bool estourar(Pilha *pilha)
{
    bool sucesso = true;
    if (!esta_vazia(pilha))
    {
        pilha->topo = pilha->topo - 1;
    }
    else
    {
        sucesso = false;
        printf("Pilha vazia\n");
    }
    return sucesso;
}

void imprimir_pilha(Pilha *pilha)
{
    printf("  ------\n");

    for (int i = pilha->topo - 1; i >= 0; i--)
    {
        printf(" | %4d |\n", pilha->valores[i]);
    }

    printf("  ------\n");
}

int main()
{
    Pilha *notas = criar_pilha(5);
    empurrar(notas, 8);
    empurrar(notas, 7);
    empurrar(notas, 15);
    empurrar(notas, 9);
    empurrar(notas, 33);
    empurrar(notas, 40);
    estourar(notas);
    estourar(notas);
    estourar(notas);
    estourar(notas);
    estourar(notas);
    estourar(notas);

    imprimir_pilha(notas);
}
