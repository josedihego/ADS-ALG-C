
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int * generate_random_array(int size, int max_value){
    int * res = malloc(size * sizeof(int));
    for(int i = 0 ; i < size; i = i +1){
        res[i] = rand() % max_value;
    }
    return res;
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
    srand(time(NULL));
    int tamanho = 2000;
    int * idades = generate_random_array(tamanho,125);
    print_array(idades,tamanho,"Antes");
    insertion_sort(idades, tamanho);
    print_array(idades,tamanho,"Depois");

    return EXIT_SUCCESS;
}