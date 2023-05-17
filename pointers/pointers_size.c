#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("sizeof(void *): %zu\n", sizeof(void *));
    printf("sizeof(char *): %zu\n", sizeof(char *));

    printf("sizeof(int *): %zu\n", sizeof(int *));
    printf("sizeof(float *): %zu\n", sizeof(float *));

    printf("sizeof(double *): %zu\n", sizeof(double *));
    printf("sizeof(char (*f) (int, int)): %zu\n", sizeof(char (*)(int,int)));

    return EXIT_SUCCESS;
}