#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



void trocar(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 45;
    int y = 71;
    printf("antes x=%d e y = %d\n", x,y);
    trocar(&x,&y);
    printf("depois x=%d e y = %d\n", x,y);

}