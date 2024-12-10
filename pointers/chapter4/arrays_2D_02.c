#include <stdio.h>
#include <stdlib.h>

int main(){
    int vector [] = {1,2,3,4,5};
    int *pv = vector;
    int size_1 = sizeof(vector)/sizeof(int);
    int size_2 = sizeof(vector[0]);
    printf("number of elements in vector: %d\n",size_1);
    printf("size of an element in the vector: %d\n",size_2);
    for(int i = 0; i < size_1; i = i +1){
        printf("%d\n",vector[i]);
    }
    printf("ADDRESS:\n");
    printf("vector address: %p\n",vector);
    printf("vector first element address: %p\n",&vector[0]);
    printf("pv address: %p\n",pv);
    printf("A pointer to entire array: %p\n", &vector);
    
    printf("SIZE OF\n");
    printf("size of vector (the content size):  %lu\n",sizeof(vector));
    printf("size of &vector[0](pointer size):  %lu\n",sizeof(&vector[0]));
    printf("size of pv:  (pointer size) %lu\n",sizeof(pv));
    printf("size of &vector:  (pointer size) %lu\n", sizeof(&vector));

}