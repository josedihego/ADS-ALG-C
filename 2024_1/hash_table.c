#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

typedef struct HashTable{
    LinkedList ** hash;
    int size;
}HashTable;

HashTable * create_hash(int size){
   HashTable * new_hash = malloc(sizeof(HashTable));
   new_hash->size = size;
   new_hash->hash = malloc(size * sizeof(LinkedList *));
   for(int i =0; i < size; i = i +1){
    new_hash->hash[i] = malloc(sizeof(LinkedList));
   }
}

int hash_function(HashTable * hash, int key){
   return (int)(floor((key * 2)/5.0)) % hash->size;
}

void insert_hash(HashTable * hash, int key){
    int position =  hash_function(hash,key);
    Node * node = create_node(key);
    insert(hash->hash[position], node);
}