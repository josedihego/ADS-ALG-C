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
    printf("conte�do pa: %d\n", *pa);
    printf("endere�o pa: %p\n", pa);
    printf("conte�do pb: %d\n", *pb);
    printf("endere�o pb: %p\n", pb);

    f(pa, pb); // TENTATIVA

    printf("%s\n", "----depois------");
    printf("conte�do pa: %d\n", *pa);
    printf("endere�o pa: %p\n", pa);
    printf("conte�do pb: %d\n", *pb);
    printf("endere�o pb: %p\n", pb);
}
