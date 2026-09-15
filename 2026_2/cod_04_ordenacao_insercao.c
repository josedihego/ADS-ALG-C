#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM 10
void insertion_sort(int * A, int length){
    for(int j = 1; j < length; j = j +1){
        int key = A[j];
        int i = j -1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
}

void imprimir(int * A, int tam){
    printf("[");
    for(int i =0; i <tam-1; i = i +1){
        printf("%d, ", A[i]);
    }
    printf("%d]\n",A[tam-1]);
}

int main(){
    srand(time(NULL));
    int * A = malloc(TAM * sizeof(int));
    for(int i = 0; i < TAM; i = i +1){
        bool cara = rand()%2 == 0? true: false;
        A[i] = rand()%100;
        if(cara) A[i] = A[i] * -1;
    }
    imprimir(A,TAM);
    insertion_sort(A,TAM);
    imprimir(A,TAM);
}
