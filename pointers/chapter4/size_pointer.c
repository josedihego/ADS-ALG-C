#include <stdio.h>
#include <stdlib.h>

int main(){
    int list [5];
    int size = sizeof(list)/sizeof(int);
    printf("size: %d\n", size);
    printf("------------------\n");
    
    int matrix[2][3] = {{2,3,4}, {5,6,7}};
    for(int i=0; i < 2 ; i = i +1){
        printf("&matrix[%d]: %p\n", i, matrix[i]);
        printf("&matrix[%d]: %p\n", i, &matrix[i]);

        printf("sizeof(matrix[%d]): %lu\n", i, sizeof(matrix[i]));
    }
}