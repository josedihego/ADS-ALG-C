#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define TAM 9
#define T 8
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
    //print_array("L", L, n1);
    //print_array("R", R, n2);
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

    int valores[TAM] = {5,10,11,30,40,11,15,20,22};
    print_array("Antes", valores, TAM);
    merge(valores,0,(0+(TAM-1))/2, TAM-1);
    print_array("Depois", valores, TAM);

    int valores2[T+1] = {-1,8,23,4,5,1,7,7,15};
    print_array("Antes", valores2, T+1);
    merge_sort(valores2,0,T-1+1);
    print_array("Depois", valores2, T+1);

}