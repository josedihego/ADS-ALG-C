#include <stdio.h>
#include <stdlib.h>
//OK
int *allocateArray(int size, int value)
{
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
    return arr;
}
//WRONG
int *allocateArrayBad(int size, int value)
{
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
    return arr;
}

int main()
{
    //OK
    int *vector = allocateArray(5, 45);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", vector[i]);
    }
    free(vector);

    //WRONG
    int *vectorBad = allocateArrayBad(5, 45);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", vectorBad[i]);
    }
    free(vectorBad);
}
