#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *nomes[] = {"maria", "antonio", "márcia"};
    // imprima a terceira letra do segundo nome
    printf("%c\n", nomes[1][2]);
    printf("%c\n", *(*(nomes + 1) + 2));
    return EXIT_SUCCESS;
}