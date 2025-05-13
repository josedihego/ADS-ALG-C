#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int * generate_random_array(int size){
    int * result = malloc(size * sizeof(int));
    for(int i = 0 ; i < size; i = i +1){
        result[i] = rand()%500  ;
    }
    return result;
}
void insertion_sort(int *A, int length)
{
    for (int j = 1; j < length; j = j + 1)
    {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] < key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}
void print_array(char * option, int *A, int length)
{
    printf("%s: [", option);
    for (int i = 0; i < length; i = i + 1)
    {
        if (i == length - 1)
            printf("%d", A[i]);
        else
            printf("%d, ", A[i]);
    }
    printf("]\n");
}
int main()
{
    srand(time(NULL));
    int size;
    printf("Informe o tamanho do array:");
    scanf("%d",&size);
    int * valores = generate_random_array(size);
    print_array("Antes", valores, size);
    insertion_sort(valores,size);
    print_array("Depois",valores,size);
}