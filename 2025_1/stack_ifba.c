#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Stack_SSA
{
    int *S;
    int size;
    int top;
} Stack_SSA;

void init_stack(Stack_SSA *ssa, int size)
{
    ssa->S = malloc(size * sizeof(int));
    ssa->size = size;
    ssa->top = -1;
}

bool is_full(Stack_SSA *ssa)
{
    return ssa->top == ssa->size - 1;
}

void push(Stack_SSA *ssa, int x)
{
    if (!is_full(ssa))
    {
        ssa->top = ssa->top + 1;
        ssa->S[ssa->top] = x;
    }
    else
    {
        printf("Pilha cheia 🌕 \n");
    }
}

bool is_empty(Stack_SSA *ssa)
{
    return ssa->top == -1;
}

int pop(Stack_SSA *ssa)
{
    if (!is_empty(ssa))
    {
        ssa->top = ssa->top - 1;
        return ssa->S[ssa->top + 1];
    }
    else
    {
        printf("Pilha vazia 🪹\n");
        return INT_MAX;
        // significa que não tem ninguém
        // na pilha
    }
}

void print_stack(Stack_SSA *ssa)
{
    printf("<< \n");
    for (int i = ssa->top; i >= 0; i = i - 1)
    {
        if (i == ssa->top)
            printf("\t top -> %d\n", ssa->S[i]);
        else
            printf("\t %d\n", ssa->S[i]);
    }
    printf(">>\n");
}

int main()
{
    Stack_SSA *s = malloc(sizeof(Stack_SSA));
    init_stack(s, 10);
    push(s, 10);
    push(s, 5);
    push(s, 15);
    print_stack(s);
}