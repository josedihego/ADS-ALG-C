#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 32767

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

int main()
{

     printf("_____Merge Test_________\n");
     int A[] = {-2, 1, 3, 4, 0, 2, 5, 6};
     merge(A, 0, 3, 7);
     printArray(A, 8);

     int B[] = {1, 7, 8, -2, 9};
     merge(B, 0, 2, 4);
     printArray(B, 5);

     int C[] = {2, 1};
     merge(C, 0, 0, 1);
     printArray(C, 2);

     int D[] = {2};
     merge(D, 0, 0, 0);
     printArray(D, 1);

     printf("_____Merge-Sort Test_________\n");
     int E[] = {6, 1, 3, 0, 9, 4, 5, 3};
     mergeSort(E, 0, 7);
     // merge(E,0,0,1);
     //     printArray(E,8);
     //     merge(E,2,2,3);
     //     printArray(E,8);
     //     merge(E,4,4,5);
     //     printArray(E,8);
     //     merge(E,6,6,7);
     //     printArray(E,8);
     //
     //     merge(E,0,1,3);
     //     printArray(E,8);
     //     merge(E,4,5,7);
     //     printArray(E,8);
     //
     //     merge(E,0,3,7);
     printArray(E, 8);

     int F[] = {1};
     mergeSort(F, 0, 0);
     printArray(F, 1);

     int G[] = {1, -1, 3};
     mergeSort(G, 0, 2);
     printArray(G, 3);

     //
     //     int D [] = {0,9,-15,10,8,6,8,3,15};
     //     mergeSort(D,0,8);
     //     printArray(D,9);

     return 0;
}