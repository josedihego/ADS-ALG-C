#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

int main()
{
    int length = 7;
    int *values = generate_random_integers(length);
    printf("\nAntes\n");
    print_array(values, length);
    insertion_sort(values, length);
    printf("\nDepois\n");
    print_array(values, length);
}