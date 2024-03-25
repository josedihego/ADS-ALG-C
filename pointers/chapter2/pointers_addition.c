#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float valores[] = {3.15f, 7.22f, 8.33f, 9.77f};
    size_t tam_valores = valores[0] ? sizeof(valores) / sizeof(valores[0]) : 0;
    for (size_t i = 0; i < tam_valores; i++)
    {
        printf("valores[%zu] %.2f (sintaxe ponteiro)\n", i, *(valores+i));
        printf("valores[%zu] %.2f (sintaxe array)\n", i, valores[i]);

    }
    
    return EXIT_SUCCESS;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    return EXIT_SUCCESS;
}
*/