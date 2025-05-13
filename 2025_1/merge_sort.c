#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

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

void merge(int * A, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;

    int * L = malloc((n1+1) * sizeof(int));
    int * R = malloc(n2+1 * sizeof(int));
    int i, j;
    for(i=0; i < n1; i = i +1){
        L[i] = A[p+i];
    }
    for(j=0; j< n2; j = j+1){
        R[j] = A[q+j+1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = 0;
    j = 0;
    print_array("L = ", L, n1+1);
    print_array("R = ", R, n2+1);
    for(int k = p; k <= r; k = k +1){
        if(L[i] < R[j]){
            A[k] = L[i];
            i = i +1;
        }
        else{
            A[k] = R[j];
            j = j+1;
        }
    }
    free(L);
    free(R);
}



void merge_sort(int * A, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}


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

int main(){
    srand(time(NULL));
    int size;
    printf("Informe o tamanho do array:");
    scanf("%d",&size);
    int * A = generate_random_array(size);
    print_array("Antes", A, size);
    merge_sort(A,0,size-1);
    print_array("Depois", A, size);
    free(A);
}