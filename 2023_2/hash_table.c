#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define A (sqrt(5)-1)/2
#define m 10

int h(int k){
   return (int)floor(m * (fmod(k * A, 1.0)));
}

int main(){
    for(int i =0; i < 20; i = i + 1){
            printf("posição: %d\n", h(i));
    }
    return EXIT_SUCCESS;
}