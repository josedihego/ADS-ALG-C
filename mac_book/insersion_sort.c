
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insertion_sort.h"

int issort(void *data, int size, int esize, 
   int (*compare)(const void *key1, const void *key2))
{
    char *a = data;
    void *key;
    int i, j;
    if ((key = (char *)malloc(esize)) == NULL)
        return -1;
    for (j = 1; j < size; j++)
    {
        memcpy(key, &a[j * esize], esize);
        i = j - 1;

        while (i >= 0 && compare(&a[i * esize], key) > 0)
        {
            memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
            i--;
        }
        memcpy(&a[(i + 1) * esize], key, esize);
    }
    free(key);
    return 0;
}

int compare_int(const void *a, const void *b)
{
    if (*(const int *)a < *(const int *)b)
    {
        return -1;
    }
    else if (*(const int *)a > *(const int *)b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_int_array(int *array, int size)
{
    printf("%c", '[');
    for (int i = 0; i < size; i = i + 1)
    {
        printf("%d", *(array + i));
        printf("%c", ',');
    }
    printf("%c", ']');
}

int main()
{
    int A[] = {2, 4, -1, 0, 4, 3, 0, 9, -5};
    print_int_array(A, 9);
    issort(A, 9, sizeof(int), compare_int);
    print_int_array(A, 9);
}