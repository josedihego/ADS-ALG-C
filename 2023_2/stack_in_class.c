#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4

typedef struct Stack
{
    int *S;
    int top;
} Stack;

void init(Stack *stack)
{
    stack->S = malloc(MAX * sizeof(int));
    stack->top = -1;
}
bool stack_full(Stack *s)
{
    return s->top + 1 == MAX;
}
bool stack_empty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int x)
{
    if (!stack_full(s))
    {
        s->top = s->top + 1;
        s->S[s->top] = x;
    }
    else
    {
        printf("%s\n", "stack overflow!");
    }
}

int pop(Stack *s)
{
    if (!stack_empty(s))
    {
        s->top = s->top - 1;
        return s->S[s->top + 1];
    }
    else
    {
        printf("%s\n", "Stack underflow");
    }
}
void print_stack(Stack *s)
{
    printf("%s\n", "Your stack:");
    for (int i = s->top; i >= 0; i = i - 1)
    {
        printf("%d\n", s->S[i]);
    }
    if (stack_empty(s))
        printf("%s\n", "Your stack is empty");
}

int main()
{
    Stack *s = malloc(sizeof(Stack));
    init(s);
    print_stack(s);
    push(s, 13);
    push(s, 7);
    push(s, 20);
    print_stack(s);
    push(s, 15);
    print_stack(s);
    push(s, -15);
    print_stack(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);
    pop(s);
    print_stack(s);

    return EXIT_SUCCESS;
}