#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Pilha cheia\n");
    } 
    else
    {
        stack[++top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Pilha vazia\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Pilha vazia\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

bool isEmpty()
{
    return top == -1;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    printf("Topo: %d\n", peek());
    printf("Elemento removido: %d\n", pop());
    printf("Topo: %d\n", peek());
    printf("pilha vazia? %s\n", isEmpty() ? "Sim" : "Não");
    return EXIT_SUCCESS;
}
