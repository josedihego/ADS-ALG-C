#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX 50

int h1(char * CPF, int size){
    int sum = 0;
    for(int i = 0; i < size; i = i +1){
        sum = sum + CPF[i];
    }
    return sum % MAX;
}

typedef struct HashTable{
    int * table;
    int size;
}HashTable;

void init(HashTable * hash, int size){
    hash->table = malloc(size * sizeof(int));
    hash->size = size;
}

int main(){
    char * CPF = "00000000000";
    printf("h1(%s) = %d\n", CPF, h1(CPF,11));
    CPF = "11111111111";
    printf("h1(%s) = %d\n", CPF, h1(CPF,11));
    CPF = "01010101010";
    printf("h1(%s) = %d\n", CPF, h1(CPF,11));
    CPF = "11111000000";
    printf("h1(%s) = %d\n", CPF, h1(CPF,11));

}