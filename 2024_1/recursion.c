#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

// Fatorial
//Ctrl + ;
/*

typedef struct Aluno{
   char * name;
   int age;
}Aluno;

struct Aluno  aluno[];
*/
int factorial(int x){
    int res = 1;
    for(int i=1; i <= x; i = i +1){
        res = res * i;
    }
    return res;
}
int factorial_rec(int x){
    if(x==0 || x==1) return 1;
    else return x * factorial_rec(x-1);
}

int fibonacci(int n){
    if(n==0) return 0;
    else if(n==1) return 1;
    else return fibonacci(n-1)+fibonacci(n-2);
    
}
int main(){
    int x;
    int n;
    printf("Informe o valor de x:");
    scanf("%d",&x);
    printf("O fatorial de %d e : %d\n", x, factorial(x));
    printf("O fat rec de %d e: %d\n", x, factorial_rec(x)); 
    printf("Informe o numero da seq de Fibonacci: ");
    scanf("%d",&n);
    printf("O %d-elemento da seq de Fibonacci e: %d\n", n, fibonacci(n)); 
    //main();
    printf("sqrt: %.2f\n", sqrt(30.0));
    return EXIT_FAILURE;
}