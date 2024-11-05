#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,y;
    printf("Informe um valor para x: ");
    scanf("%d", &x);
    printf("Informe um valode para y: ");
    scanf("%d", &y);
    if(x>5){
        printf("x > 5\n");
    }
    if(x>y){
        printf("x> y \n");
    }
    if(y > 8){
        printf("y > 8 \n");
    }
}