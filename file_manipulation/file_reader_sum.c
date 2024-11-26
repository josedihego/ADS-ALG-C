#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp_in = fopen("lists.txt", "r");
    FILE *fp_out = fopen("saida.txt", "w");

    if (fp_in == NULL || fp_out == NULL)
    {
        printf("Arquivos não podem ser abertos.");
        return EXIT_FAILURE;
    }
    char line[255];
    const char comma[] = ",";
    char *slice;

    while (fgets(line, 255, fp_in) != NULL)
    {
        //strtok: (1)não é thread-safe e (2) modifica a string
        slice = strtok(line, comma);
        int soma = 0;
        int value;
        char text[20];
        while (slice != NULL)
        {
            value = atoi(slice);
            soma = soma + value;
            slice = strtok(NULL, comma);
        }
        //printf("soma: %d ", soma);
        sprintf(text, "%d%s", soma, "\n");
        //sprintf(text, "%s%s",text, "\n");
        //printf("texto: %s", text);
        fputs(text, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
