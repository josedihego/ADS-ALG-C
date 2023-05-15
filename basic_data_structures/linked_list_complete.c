#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
} Node;

typedef struct List
{
    struct Node *head;
} List;

void insertL(List *L, Node *x)
{
    if (L->head != NULL)
    {
        L->head->prev = x;
    }
    x->next = L->head;
    x->prev = NULL;
    L->head = x;
}

void removeL(List *L, Node *x)
{
    if (x->prev != NULL)
    {
        x->prev->next = x->next;
    }
    else
    {
        L->head = x->next;
    }
    if (x->next != NULL)
    {
        x->next->prev = x->prev;
    }
    free(x);
}
Node *searchL(List *L, int data)
{
    Node *x = L->head;
    while (x != NULL && x->data != data)
    {
        x = x->next;
    }
    return x;
}

void printL(List *L)
{
    Node *x = L->head;
    while (x != NULL)
    {
        printf("%d, ", x->data);
        x = x->next;
    }
    printf("\n");
}

void init(List *L)
{
    L->head = NULL;
}

int main(void)
{
    int i;
    List *L = malloc(sizeof(List));
    Node *n;
    init(L);

    for (i = 0; i <= 5; i++)
    {
        n = malloc(sizeof(Node));
        n->data = i;
        insertL(L, n);
    }
    printL(L);

    n = searchL(L, 5);
    removeL(L, n);
    printL(L);

    n = searchL(L, 0);
    removeL(L, n);
    printL(L);

    n = searchL(L, 3);
    removeL(L, n);
    printL(L);

    n = searchL(L, 90);
    if (n == NULL)
        printf("%s", "Elemento nao encontrado\n");
    
    return EXIT_SUCCESS;
}
