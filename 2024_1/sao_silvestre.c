#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<limits.h>

void merge(int * A, int p, int q, int r){
    int n1 = q - p +1;
    int n2 = r - q;
    //printf("%d\n",n1);
    //printf("%d\n",n2);
    int * L = malloc((n1+1) * sizeof(int));
    int * R = malloc((n2+1) * sizeof(int));
    for(int i=0; i < n1; i = i +1){
        L[i]=A[p+i];
    }
    L[n1]= INT_MAX;
    for(int j=0; j < n2; j = j +1){
        R[j]= A[q+j+1];
    }
    R[n2] = INT_MAX;
    int i = 0, j = 0;
    for(int k = p; k <= r; k = k +1){
        if(L[i] <=  R[j]){
            A[k] = L[i];
            i = i + 1;
        }
        else{
            A[k] = R[j];
            j = j + 1;
        }
    }
    free(L);
    free(R);
}

void merge_sort(int * A, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        merge_sort(A,p,q);// in�cio ao meio
        merge_sort(A,q+1,r);// meio+1 ao fim
        merge(A,p,q,r);
    }
}

int * generate_random_array(int size, int max_value){
    int * res = malloc(size * sizeof(int));
    for(int i = 0 ; i < size; i = i +1){
        res[i] = rand() % max_value;
    }
    return res;
}

int * copy_array(int * src, int size){
    int * dst = malloc(size * sizeof(int));
    for(int i = 0 ; i < size; i = i + 1){
        dst[i] = src[i];
    }
    return dst;
}

int insertion_sort(int * A, int size){
    for(int j = 1; j < size; j = j +1 ){
        int key = A[j];
        int i = j - 1;
        while (i > -1 && A[i] > key){
            A[i+1] = A[i];
            i = i -1;
        }
        A[i+1] = key;
    }
    return 0;
}
void print_array(int * A, int size, char * help_text){
    printf("%s: [", help_text);
    for(int i = 0; i < size-1; i =i +1){
        printf("%d,", A[i]);
    }
    printf("%d]\n", A[size-1]);
}

int main(){
    clock_t start, end;
    srand(time(NULL));
    int tamanho = 100000 * 2;
    int * idades = generate_random_array(tamanho,125);
    int * copy_idades  =  copy_array(idades,tamanho);

    start  =  clock();
    merge_sort(copy_idades,0,tamanho-1);
    end =  clock();
    float diff = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("Merge sort cost in seconds: %.2f\n", diff);


    //print_array(idades,tamanho,"Antes");
    start = clock();
    insertion_sort(idades, tamanho);
    end =  clock();
    diff = ((double)(end-start))/CLOCKS_PER_SEC;
    //print_array(idades,tamanho,"Depois");
    printf("Insertion sort cost in seconds: %.2f\n", diff);

    

    return EXIT_SUCCESS;
}