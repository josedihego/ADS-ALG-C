#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct My_List
{
    Node *head;
} My_List;

Node *create_node(int key)
{
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

My_List *create_list()
{
    My_List *ml = malloc(sizeof(My_List));
    ml->head = NULL;
    return ml;
}

Node *search_list(My_List *ml, int key)
{
    Node *x = ml->head;
    while (x != NULL && x->key != key)
    {
        x = x->next;
    }
    return x;
}

void insert_list(My_List *ml, Node *x)
{
    x->next = ml->head;
    if (ml->head != NULL)
    {
        ml->head->prev = x;
    }
    ml->head = x;
    x->prev = NULL;
}

int main()
{
    My_List *ml = create_list();
    insert_list(ml, create_node(5));
    insert_list(ml, create_node(7));
    insert_list(ml, create_node(0));

    /**
    Node * n5 = create_node(5);
    Node * n7 = create_node(7);
    Node * n0 = create_node(0);
    ml->head = n5;
    n5->next = n7;
    n7->prev = n5;
    n7->next = n0;
    n0->prev = n7;
 */

    Node *res = search_list(ml, 10);
    if (res != NULL)
        printf("res: %d\n", res->key);
    else
        printf("res: NULL\n");
}