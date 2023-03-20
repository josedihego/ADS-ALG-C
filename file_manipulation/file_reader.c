#include <stdio.h>

int main() {
    FILE *fp;
    char line[255];

    fp = fopen("lists.txt", "r");
    if (fp == NULL) {
        printf("Arquivo não pode ser aberto.");
        return 1;
    }

    while (fgets(line, 255, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
