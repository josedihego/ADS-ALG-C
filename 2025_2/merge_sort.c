#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define TAM 9

typedef struct Person
{
    char *id;
    char *name;
    int age;
} Person;



void print_array(char *modo, int *A, int tam)
{
    printf("\n %s:  [", modo);
    for (int i = 0; i < tam; i = i + 1)
    {
        if (i == tam - 1)
        {
            printf("%d", A[i]);
        }
        else
        {
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

int * gerar_array_grandao(int tam){
    int * array_grandao = malloc(tam * sizeof(int));
    for(int i =0; i < tam; i = i +1){
        array_grandao[i] = rand()%50000;
    }
    return array_grandao;
}

int * copiar_array_grandao(int * array, int tam){
    int * copia = malloc(tam * sizeof(int));
    for(int i = 0; i < tam; i = i +1){
        copia[i] = array[i];
    }
    return copia;
}

void merge(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *L = malloc((n1 + 1) * sizeof(int));
    int *R = malloc((n2 + 1) * sizeof(int));
    int i, j;
    for (i = 0; i < n1; i = i + 1)
    {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j = j + 1)
    {
        R[j] = A[q + j + 1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = j = 0;
    for (int k = p; k <= r; k = k + 1)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
    free(L);
    free(R);
}

void merge_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void troca(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void troca_ponteiro(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main()
{
    srand(time(NULL));
    int a, b;
    a = 10;
    b = 20;
    troca(a, b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    troca_ponteiro(&a, &b);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    Person *p = malloc(sizeof(Person));
    p->age = 20;
    p->id = "111.111.111-11";
    p->name = "Eduardo";

    int valores[TAM] = {5,3,40,8,99,11,44,37,26};
    print_array("Antes", valores, TAM);

    clock_t inicio = clock();
    merge_sort(valores,0,TAM-1);
    clock_t fim = clock();
    double intervalo_segundos = (fim-inicio)/CLOCKS_PER_SEC;
    printf("Tempo de execução é %.6f\n", intervalo_segundos);

    //print_array("Depois", valores, TAM);


    int tam = 1000000;
    int * array_grandao = gerar_array_grandao(tam);
    int * copia = copiar_array_grandao(array_grandao,tam);
    //print_array("Array Grandão", array_grandao, tam);
    inicio = clock();
    merge_sort(array_grandao,0,tam-1);
    fim = clock();
    intervalo_segundos = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    printf("MS: Tempo com array grandão é: %.6f s\n", intervalo_segundos);

    inicio = clock();
    insertion_sort(copia, tam);
    fim = clock();
    intervalo_segundos = ((double)(fim-inicio))/CLOCKS_PER_SEC;
    printf("IS: Tempo com array copia é:   %.6f s\n", intervalo_segundos);


}