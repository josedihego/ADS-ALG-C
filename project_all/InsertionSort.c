#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *A, int length)
{
     int j;
     for (j = 1; j < length; j++)
     {
          int key = A[j];
          int i = j - 1;
          while (i >= 0 && A[i] > key)
          {
               A[i + 1] = A[i];
               i = i - 1;
          }
          A[i + 1] = key;
     }
}

void printArray(int *A, int length)
{
     int j;
     printf("%c", '[');
     for (j = 0; j < length; j++)
     {
          if (j == (length - 1))
               printf("%d", *(A + j));
          else
               printf("%d, ", *(A + j));
     }
     printf("%s", "]\n");
}

int main(int argc, char *argv[])
{
     int A[] = {2, 4, -1, 0, 4, 3, 0, 9, -5};
     insertionSort(A, 9);
     printArray(A, 9);
     return 0;
}
