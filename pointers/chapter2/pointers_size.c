#include <stdio.h>
#include <stdlib.h>

int main()

{
    printf("%s", "#---Tamanhos dos tipos de dado---#\n");

    printf("sizeof(void ): %d\n", sizeof(void ));
    printf("sizeof(char ): %d\n", sizeof(char ));

    printf("sizeof(short): %d\n", sizeof(short ));
    printf("sizeof(int ): %d\n", sizeof(int ));
    printf("sizeof(long): %d\n", sizeof(long ));

    printf("sizeof(float ): %d\n", sizeof(float ));

    printf("sizeof(double ): %d\n", sizeof(double ));

    printf("%s", "#---Tamanhos dos ponteiros---#\n");

    printf("sizeof(void *): %zu\n", sizeof(void *));
    printf("sizeof(char *): %zu\n", sizeof(char *));

    printf("sizeof(int *): %zu\n", sizeof(int *));
    printf("sizeof(float *): %zu\n", sizeof(float *));

    printf("sizeof(double *): %zu\n", sizeof(double *));
    printf("sizeof(char (*f) (int, int)): %zu\n", sizeof(char (*)(int, int)));

    return EXIT_SUCCESS;
}