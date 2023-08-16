#include <stdio.h>
#include <stdlib.h>


void swap(int * pnum1, int * pnum2){
    int tmp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 =  tmp;
}

int main(){
    int n1 = 5;
    int n2 = 10;
    printf("antes\n n1 = %d, n2 = %d\n", n1, n2);
    swap(&n1, &n2);
    printf("depois\n n1 = %d, n2 = %d\n", n1, n2);
}