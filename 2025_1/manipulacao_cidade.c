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
        // criar os caminhos
        // colocar no array caminhos
    }
    // para a cidade c25 calcular os menores caminhos para
    // todas as outras 49 cidades
    

    fclose(fp);
    return EXIT_SUCCESS;
}
