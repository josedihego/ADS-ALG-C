
#include <stdio.h>
#include<stdlib.h>

int factor(int v){
    if(v==1) return 1;
    else return v * factor(v-1);
}


// 1, 1, 2, 3, 5, 8

int fibonacci(int p){
   if (p ==1)return 0;
   else if (p ==2)return 1;
   else return fibonacci(p-1) + fibonacci(p-2);
}
int main(){
    int x = 10;
    int res = factor(x);
    printf("Fatoria de %d é %d\n", x, res);
    int p = 23;
    int resfib = fibonacci(p);
    printf("Elemento %d-essimo de Fibonacci é %d\n", p, resfib);

}