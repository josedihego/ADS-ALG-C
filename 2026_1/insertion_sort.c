#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define TAM 1000000

void insertion_sort(int * A,int size){
    for(int j=1; j < size; j = j+1){
        int key = A[j];
        int i = j - 1;
        while(i >=0 && A[i] > key){
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
}

void imprimir_array(int * valores, int tamanho){
    printf("\n[");
    for(int i =0; i < tamanho; i = i +1){
        if(i < tamanho-1){
            printf("%d, ", valores[i]);
        }
    }
    printf("%d]\n",valores[tamanho-1]);
}

int main(){
    srand(time(NULL));
    int * valores = malloc(TAM * sizeof(int));
    for(int i = 0; i < TAM ; i = i +1){
        valores[i] = rand()%100;
    }
    //imprimir_array(valores,TAM);
    time_t inicio = clock();
    insertion_sort(valores,TAM);
    time_t final = clock();
    float diferenca = (final - inicio)/CLOCKS_PER_SEC;
    printf("Para ordenar o array foram gastos %.6f segundos\n",diferenca);
    //imprimir_array(valores,TAM);


}
