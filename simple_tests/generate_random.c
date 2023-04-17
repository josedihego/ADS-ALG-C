#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 500
#define QNT 100

int main(){
    srand(time(NULL));
    int * numbers =  (int *)malloc(sizeof(int) * QNT);
    for(int i = 0; i <QNT;  i = i +1)
    {
        numbers[i] = rand() % MAX_NUM;
    }
    for(int i = 0; i <QNT;  i = i +1)
    {
        printf("%d\n", numbers[i]);
    
    }
    free(numbers);
}