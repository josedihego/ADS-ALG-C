#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    int *pi = &num;
    printf("endereço num: %p, valor de num: %d\n", &num, num);
    printf("endereço pi: %p, valor de pi: %p\n", &pi, pi);
    return EXIT_SUCCESS;
}