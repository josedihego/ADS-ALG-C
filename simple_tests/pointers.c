#include<stdio.h>
#include <stdlib.h>

// ##########
// TEST 1
// ##########
int f(int **p){
    int a = 10;
    *p =  &a;
    printf("dentro de f: %d \n",**p);
    return 0;
}

/*
int main(){
    int ** pointer = malloc(sizeof(int));
    f(pointer);
    //PERIGO dangling pointer depois do retorno de f
    printf("fora de f: %d \n",**pointer);
    printf("%s\n", "fim");
}
*/

// ##########
// END TEST 1
// ##########


// ##########
// TEST 2
// ##########
int g (int ** p ){
    if( (*p = (int *)malloc(sizeof(int))) == NULL){
        return -1;
    }
    return 0;
}
/*
int main(){
    // segmentation fault
    int ** pointer;
    g(pointer);
}
*/
int main(){
    // segmentation fault
    int ** pointer = malloc(sizeof(int));
    g(pointer);
}

// ##########
// END TEST 2
// ##########