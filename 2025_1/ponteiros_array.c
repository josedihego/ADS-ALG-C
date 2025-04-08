#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam;
    printf("Informe o tamanho do array:");
    printf("Endereço tam: %p\n", &tam);
    scanf("%d", &tam);
    int *valores = malloc(tam * sizeof(int));
    valores[0] = 10;
    valores[1] = 30;
    printf("valores[0] = %d\n", valores[0]);
    valores = malloc(tam * sizeof(int));
    free(valores);

}