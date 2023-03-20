#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("lists.txt", "r");
    FILE *f_out = fopen("saida.txt", "w");

    if (fp == NULL || f_out == NULL)
    {
        printf("Arquivos não podem ser abertos.");
        return 1;
    }
    char line[255];
    const char comma[] = ",";
    char *slice;

    while (fgets(line, 255, fp) != NULL)
    {
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
        printf("soma: %d ", soma);
        sprintf(text, "%d", soma);
        sprintf(text, "%s%s",text, "\n");
        printf("texto: %s", text);
        fputs(text, f_out);
    }

    fclose(fp);
    fclose(f_out);
    return 0;
}
