#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char texto[100] = "1+2+3+1+2+3+1+1";
    const char separador[] = "+";
    char * pedaco;
    pedaco = strtok(texto, separador);
     while (pedaco != NULL)
        {
            int valor = atoi(pedaco);
            pedaco = strtok(NULL, separador);
            printf("%d\n",valor);
        }
}