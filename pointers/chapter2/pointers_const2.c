#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 7;
    const int b = 8;
    const int *p = &a;
    
    printf("a = %d \n", *p);
    p = &b;
    printf("b = %d \n", *p);
    return EXIT_SUCCESS;
}