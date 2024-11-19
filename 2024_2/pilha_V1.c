#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct My_Stack{
    int * S;
    int top;
}My_Stack;

void init_stack(My_Stack * ms, int size){
    ms->S = malloc(size * sizeof(int));
    ms->top = -1;
}

void push(My_Stack * ms, int e){
    ms->top = ms->top + 1;
    ms->S[ms->top] = e;
}

int pop(My_Stack * ms){
    ms->top = ms->top -1;
    return ms->S[ms->top +1];
}