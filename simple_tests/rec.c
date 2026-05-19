#include <stdio.h>
#include <stdlib.h>

#define N 5
#define FIB 50
int fatorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fatorial(n - 1);
}

int fibonacci(int enesimo, int * steps)
{
    (*steps) = *(steps) + 1;
    if (enesimo == 1)
   
        return 0;
    
    if (enesimo == 2)
    
        return 1;
    
    return fibonacci(enesimo - 1, steps) + fibonacci(enesimo - 2, steps);
}

int main()
{
    int res = fatorial(N);
    int steps = 0;
    printf("fatorial(%d)= %d \n", N, res);
    res = fibonacci(FIB,&steps);
    printf("fibonacci(%d) = %d and steps = %d\n", FIB, res,steps);
}