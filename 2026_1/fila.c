#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Cliente{
    char * CPF;
    char * nome;
    struct Cliente * anterior;
}Cliente;

typedef struct Fila{
    Cliente * primeiro;
    Cliente * ultimo;
}Fila;