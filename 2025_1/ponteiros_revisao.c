#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void swap_ok(int * pa, int * pb){
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

int main(){
    int x=20,y=10;
    printf("Antes x = %d, y = %d\n", x, y);
    swap(x,y);
    printf("Depois x = %d, y = %d\n", x, y);

    swap_ok(&x,&y);
    printf("Depois do swap OK x = %d, y = %d\n", x, y);

}