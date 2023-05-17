#include<stdio.h>
#include<stdlib.h>

int main(){
    int *pi;
    char * pc;
    pi = NULL; // DIFERENTE do char NUL que tem valor '\0' (zero em decimal)
    if(pi){
        printf("%s","pi não nulo\n");
    }
    else{
        printf("%s","pi nulo\n");
    }
    pi= 0;
    // pi = 100;//erro de sintaxe em alguns compiladores
      if(pi){
        printf("%s","pi não nulo\n");
    }
    else{
        printf("%s","pi nulo\n");
    }
    return EXIT_SUCCESS;
}