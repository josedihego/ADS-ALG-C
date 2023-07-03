#include <stdio.h>
#include <stdlib.h>

int f(int *x, int *y)
{
    int *z = malloc(sizeof(int));
    z = x;
    x = y;
    y = z;
    //free(z);
}
int main()
{
    int *pa = malloc(sizeof(int));
    int *pb = malloc(sizeof(int));
    *pa = 3;
    *pb = 7;
    printf("%s\n", "----antes------");
    printf("conteúdo pa: %d\n", *pa);
    printf("endereço pa: %p\n", pa);
    printf("conteúdo pb: %d\n", *pb);
    printf("endereço pb: %p\n", pb);

    f(pa, pb); // TENTATIVA

    printf("%s\n", "----depois------");
    printf("conteúdo pa: %d\n", *pa);
    printf("endereço pa: %p\n", pa);
    printf("conteúdo pb: %d\n", *pb);
    printf("endereço pb: %p\n", pb);
}
