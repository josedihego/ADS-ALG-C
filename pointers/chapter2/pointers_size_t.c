#include <stdio.h>
#include <stdlib.h>

/**
 * It is good practice to use size_t when declaring variables for sizes such
as the number of characters and array indexes. It should be used for
loop counters, indexing into arrays, and sometimes for pointer
arithmetic.
*/

void print_strings(char *valores[], size_t tam)
{
    if (valores[0])
    {
        // não funciona pois retorna tamanho de char **
        //size_t tam = sizeof(valores) / sizeof(valores[0]);
        size_t i = 0;
        while (i < tam)
        {
            printf("array[%zu] = %s \n", i, valores[i]);
            i = i + 1;
        }
       
    }
    else
    {
         printf("%s", "Array vazio\n");
    }
}

int main()
{
    char *nomes[] = {"maria", "carla", "bruna"};
    size_t tam = sizeof(nomes) / sizeof(nomes[0]);
    printf("tamanho de array nomes: %zu\n", tam);
    print_strings(nomes, tam);
    return EXIT_SUCCESS;
}