#include <stdio.h>
#include <stdlib.h>

#define TAM 9

void print_array(char * modo, int * A, int tam){
    printf("\n %s:  [", modo);
    for(int i = 0; i < tam; i = i +1){
        if(i==tam-1){
             printf("%d", A[i]);
        }
        else{
            printf("%d, ", A[i]);
        }
    }
    printf("]\n");
}
int main(){
    int valores [TAM] = {8,3,100,20,11,15,-1,0,9};
    print_array("Antes",valores,TAM);
}