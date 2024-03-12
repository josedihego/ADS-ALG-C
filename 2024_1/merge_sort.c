#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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
    for(int k = p; k < r; k = k +1){
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

void print_array(int * A, int size, char * help_text){
    printf("%s: [", help_text);
    for(int i = 0; i < size-1; i =i +1){
        printf("%d,", A[i]);
    }
    printf("%d]\n", A[size-1]);
}



int main(){
    int * idades = malloc(5 * sizeof(int));
    idades[0] = 10;
    idades[1] = 20;
    idades[2] = 25;
    idades[3] = 5;
    idades[4] = 10; 
    print_array(idades,5, "Antes");
    merge(idades,0,2,4);
    print_array(idades,5, "Depois");

    
}