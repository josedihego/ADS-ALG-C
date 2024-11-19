#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

int *generate_random_integers(int size)
{
    srand(time(NULL));
    int *values = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i = i + 1)
    {
        values[i] = rand() % 101;
    }
    return values;
}
void insertion_sort(int *A, int length)
{
    for (int j = 1; j < length; j = j + 1)
    {
        int key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

void print_array(int *A, int length)
{
    for (int i = 0; i < length; i = i + 1)
    {
        if (i == length - 1)
            printf("%d ", A[i]);
        else
            printf("%d, ", A[i]);
    }
    printf("\n");
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
    L[n1] = INT_MAX;
    for(j=0; j < n2; j = j+1){
        R[j] = A[q+j+1];
    }
    R[n2] = INT_MAX;
    i = j = 0;
    for(int k = p ; k <= r; k = k +1){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i +1;
        }
        else{
            A[k] = R[j];
            j = j +1;
        }
    }
    free(L);
    free(R);
}

void print_array2(char * type, int *A, int length)
{
    printf("%s", type);
    for (int i = 0; i < length; i = i + 1)
    {
        if (i == length - 1)
            printf("%d ", A[i]);
        else
            printf("%d, ", A[i]);
    }
    printf("\n");
}

void merge_sort(int * A, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }

}
int main()
{

    int length = 50000000;
    int *values = generate_random_integers(length);
    //printf("\nAntes\n");
    //print_array(values, length);
    clock_t start = clock();
   // insertion_sort(values, length);
    merge_sort(values,0,length-1);
    clock_t end = clock();
    double seconds = (double)(end-start)/ CLOCKS_PER_SEC;
    printf("Se passaram %.2f\n", seconds);
    //printf("\nDepois\n");
    //print_array(values, length);
}