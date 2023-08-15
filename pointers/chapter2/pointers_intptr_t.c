#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 32;
    char c = 'A';
    char * str = "Olá";
    float f = 12.4;
    float * pf;
    __intptr_t *p ;
    p = &i;
    printf("i: %d\n", *p);
    p = &c;
    printf("c: %c\n", *p);
    p = str;
    printf("str: %s\n", p);
    p =  &f;
    printf("f: %.2f\n", *p);
    pf = &f;
    printf("f: %.2f\n", *pf);

    return EXIT_SUCCESS;
}