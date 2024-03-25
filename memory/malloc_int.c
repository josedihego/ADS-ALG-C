#include<stdio.h>
#include<stdlib.h>

int main(){
    int *pi = (int *) malloc(sizeof(int));
    *pi = 5;
    printf("address in pi: %p\n", pi);
    printf("pi: %d\n", *pi);
    free(pi);
    return EXIT_SUCCESS;

}