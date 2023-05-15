#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(struct Node **top, int data)
{
    struct Node *node = newNode(data);
    node->next = *top;
    *top = node;
    printf("Adicionado: %d\n", data);
}

int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Pilha vazia\n");
        return -1;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    int data = temp->data;
    free(temp);
    printf("Removido: %d\n", data);
    return data;
}

int peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Pilha vazai\n");
        return -1;
    }
    return top->data;
}

int isEmpty(struct Node *top)
{
    return top == NULL;
}

int main()
{
    struct Node *top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);

    printf("Topo: %d\n", peek(top));
    printf("Topo removido: %d\n", pop(&top));
    printf("Topo: %d\n", peek(top));
    printf("Pilha vazia? %s\n", isEmpty(top) ? "Sim" : "Não");
    return 0;
}
