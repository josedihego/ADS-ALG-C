#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT 32767
#define MAX_NUMBER 500

void merge(int *A, int p, int q, int r)
{
     int n1 = q - p + 1;
     int n2 = r - q;
     int i, j, k;

     int *L = malloc((n1 + 1) * sizeof(int));
     int *R = malloc((n2 + 1) * sizeof(int));

     for (i = 0; i < n1; i++)
          *(L + i) = A[p + i];
     for (j = 0; j < n2; j++)
          R[j] = *(A + (q + j + 1));

     L[n1] = MAX_INT;
     R[n2] = MAX_INT;

     i = j = 0;
     for (k = p; k <= r; k++)
     {
          if (L[i] <= R[j])
          {
               A[k] = L[i];
               i++;
          }
          else
          {
               A[k] = R[j];
               j++;
          }
     }
     free(L);
     free(R);
}

void mergeSort(int *A, int p, int r)
{

     if (p < r)
     {
          int q = (p + r) / 2;
          mergeSort(A, p, q);
          mergeSort(A, q + 1, r);
          merge(A, p, q, r);
     }
}

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

int *generate_random_numbers(int qnt)
{
     int *result = (int *)malloc(qnt * sizeof(int));
     for (int i = 0; i < qnt; i = i + 1)
     {
          result[i] = rand() % (MAX_NUMBER + 1);
     }
     return result;
}

int main()
{
     srand(time(NULL));
     
     time_t inicio, fim;
     inicio = clock();
     fim = clock();
     float tempo_transcorido = ((float)fim - inicio) / CLOCKS_PER_SEC;
}