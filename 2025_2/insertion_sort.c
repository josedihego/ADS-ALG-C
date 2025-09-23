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

void insertion_sort(int * A, int tam){
    for(int j = 1; j < tam; j = j +1){
        int key = A[j];
        int i = j-1;
        while(i >= 0 && A[i]>key){
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
}

int main(){
    int valores [TAM] = {8,3,100,20,11,15,-1,0,9};
    print_array("Antes",valores,TAM);
    insertion_sort(valores,TAM);
    print_array("Depois",valores,TAM);
}