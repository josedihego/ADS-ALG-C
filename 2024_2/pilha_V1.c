#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct My_Stack
{
    int *S;
    int top;
    int capacity;
} My_Stack;

void init_stack(My_Stack *ms, int size)
{
    ms->S = malloc(size * sizeof(int));
    ms->top = -1;
    ms->capacity = size;
}

bool is_empty(My_Stack *ms)
{
    return ms->top == -1;
}
bool is_full(My_Stack *ms)
{
    return ms->top == ms->capacity - 1;
}

void push(My_Stack *ms, int e)
{
    if (!is_full(ms))
    {
        ms->top = ms->top + 1;
        ms->S[ms->top] = e;
    }
    else
    {
        printf("Stack is full!\n");
    }
}

int pop(My_Stack *ms)
{
    if (!is_empty(ms))
    {
        ms->top = ms->top - 1;
        return ms->S[ms->top + 1];
    }
    else
    {
        printf("Stack is empty!\n");
        return EXIT_FAILURE;
    }
}
void print_stack(My_Stack * ms){
    for(int i = ms->top; i > -1; i = i -1){
        printf("%d\n",ms->S[i]);
    }
}

int main()
{
    // printf("%d\n",sizeof(My_Stack));
    My_Stack *odd = malloc(sizeof(My_Stack));
    init_stack(odd, 23);
    push(odd, 7);
    push(odd, 20);
    push(odd, 5);
    print_stack(odd);
    pop(odd);
    printf("After pop\n");
    print_stack(odd);
}