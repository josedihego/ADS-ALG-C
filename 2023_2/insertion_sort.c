#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *A, int lenght)
{
    int key;
    for (int j = 1; j < lenght; j = j + 1)
    {
        key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

void print_array(int *A, int lenght)
{
    printf("%s", "[");
    for (int i = 0; i < lenght-1; i = i + 1)
    {
        printf("%d, ", A[i]);
    }
    printf("%d]\n", A[lenght - 1]);
    // printf("%s\n", "]");
}

int main()
{
    int valores[10] = {13, 20, 1, 10, 13, 99, 50, 51, 27, 0};
    printf("%s\n", "Antes:");
    print_array(valores, 10);
    printf("%s\n", "Depois:");
    insertion_sort(valores, 10);
    print_array(valores, 10);

    return EXIT_SUCCESS;
}