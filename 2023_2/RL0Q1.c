#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINE_MAX_SIZE 100

int main(){
    FILE* file_in = fopen("L0Q1.in","r");
    FILE* file_out = fopen("L0Q1.out", "w");
    if(file_in == NULL || file_out==NULL){
        printf("%s\n", "Falha na criação dos arquivos!");
        return EXIT_FAILURE;
    }
    char * line = malloc(LINE_MAX_SIZE * sizeof(char));
    const char * separator = " ";
    char * slice;
    int sum = 0;
    while(fgets(line,LINE_MAX_SIZE,file_in) != NULL){
        //printf("%s", line);
        slice = strtok(line, separator);
        while(slice != NULL){
            int value = atoi(slice);
            sum = sum + value;
            slice = strtok(NULL, separator);
        }
        //printf("soma: %d\n", sum);
        fprintf(file_out,"soma: %d\n", sum);
        sum = 0;
    }
    free(line);
    fclose(file_in);
    fclose(file_out);
}