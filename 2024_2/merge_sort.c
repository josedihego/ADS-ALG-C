#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

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

void print_array(char * type, int *A, int length)
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

    int  A [10] = {7, 9,0,0,-1,2,4,5,1,1};
    print_array("Antes: ", A, 10);
    merge_sort(A,0,9);
    print_array("Depois: ", A, 10);


}