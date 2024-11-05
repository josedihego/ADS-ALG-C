#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


void merge(int * A, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int * L = malloc((n1+1) * sizeof(int));
    int * R = malloc((n2+1) * sizeof(int));
    int i, j;
    for(i=0; i < n1; i = i+1){
        L[i]= A[p+i-0];
    }
    
    // bus
}

int main(){

}