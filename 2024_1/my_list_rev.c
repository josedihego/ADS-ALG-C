#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int key;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
} LinkedList;

void insert(LinkedList *l, Node *n)
{
    if (l->head == NULL)
    {
        l->head = l->tail = n;
    }
    else
    {
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }
}

Node *create_node(int key)
{
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

Node * search(LinkedList * l, int key){
    Node * x = l->tail;
    while(x!=NULL && x->key!=key){
        x = x->prev;
    }
    return x;
}

void remove_list(LinkedList * l, Node * x){
    if(l->head==x && l->tail == x){
        l->head = l->tail = NULL;
    }
    else if(l->head==x){
        l->head->next->prev = NULL;
        l->head = l->head->next;
    }
    else if(l->tail==x){
        l->tail->prev->next = NULL;
        l->tail = l->tail->prev;
    }
    else{
        x->next->prev  = x->prev;
        x->prev->next = x->next;
    }
    free(x);
}
int main()
{
    LinkedList *l = malloc(sizeof(LinkedList));
    insert(l, create_node(5));
    insert(l, create_node(8));
    insert(l, create_node(-1));
    insert(l, create_node(9));
    insert(l, create_node(0));
    Node * x =  search(l,-1);
    if(x!=NULL) remove_list(l,x);
    remove_list(l, search(l,8));
    remove_list(l, search(l,9));
    remove_list(l, search(l,0));


    printf("Fim");
}
