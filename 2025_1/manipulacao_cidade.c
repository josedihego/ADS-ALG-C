#include <stdio.h>
#include <stdlib.h>


typedef struct Caminho{
    char * origem;
    char * destino;
    float distancia;
}Caminho;



int main() {
    FILE *fp;
    char line[255];

    Caminho * caminhos [1016];
    //Caminho ** caminhos;  // opção 2

    fp = fopen("cidades.in", "r");
    if (fp == NULL) {
        printf("Arquivo não pode ser aberto.");
        return EXIT_FAILURE;
    }

    while (fgets(line, 255, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
