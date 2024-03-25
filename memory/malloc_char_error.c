#include <stdio.h>
#include <stdlib.h>

int main()
{

    // OK
    char *pt = (char *)malloc(6 * sizeof(char));
    for (int i = 0; i < 5; i = i + 1)
    {
        pt[i] = 'a';
    }
    pt[5] = '\0';
    printf("%s\n", pt);
    free(pt);

    // POTENCIALMENTE ERRADO
    char *pc = (char *)malloc(6 * sizeof(char));
    for (int i = 0; i < 8; i = i + 1)
    {
        pc[i] = 'a';
    }
    printf("%s\n", pc);
    free(pc);

    return EXIT_SUCCESS;
}