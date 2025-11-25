#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int key;
    struct Node * next;
    struct Node * prev;
}Node;

typedef struct List{
    Node * head;
}List;

List * create_list(){
    List * new_list = malloc(sizeof(List));
    new_list->head = NULL;
    return new_list;
}

Node * create_node(int key){
    Node * new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert(List * l, Node * n){
    if(l->head == NULL){
        l->head = n;
    }
    else{
        Node * can_tail = l->head;
        while(can_tail->next != NULL){
            can_tail = can_tail->next;
        }
        can_tail->next = n;
        n->prev = can_tail;
    }
}


void insert_v2(List * l, Node * n){
    if(l->head == NULL){
        l->head = n;
    }
    else{
        n->next = l->head;
        l->head->prev = n;
        l->head = n;
    }
}

void remove(List * l , int key){
    Node * to_remove = l->head;
    while(to_remove!=NULL && to_remove->key!= key){
        to_remove = to_remove->next;
    }
    if(to_remove == l->head){
        l->head = l->head->next;
        l->head->prev = NULL;
        free(to_remove);
    }
}

int main(){
    int l_i = 5;
    int r_i = 8;
    int i = 4;
    Node * n = create_node(i);
}