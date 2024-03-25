#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){

    clock_t start, end;

    start = clock();

    int k = 0;
    for(int i = 100000; i >0;  i = i -1){
        k = k+1;
    }
   
    end = clock();

    double elapsed_time =  ((double)end - start)/CLOCKS_PER_SEC; 

    printf("Elapsed time: %f seconds\n", elapsed_time);

}