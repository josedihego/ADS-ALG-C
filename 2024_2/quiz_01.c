#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    printf("Informe um valor: ");
    scanf("%d", &x);
    if(x > 10 && x<300 && x%2==0 ){ //&& x%2==1
        printf("Entrou no IF\n");
    }
    else{
        printf("Entrou no ELSE\n");
    }
}