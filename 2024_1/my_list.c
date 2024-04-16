#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int key;
    struct Node * next;
    struct Node * prev;
}Node;

typedef struct List{
    Node * head;
    Node * tail;
}List;

Node * create_node(int k){
    Node * new = malloc(sizeof(Node));
    new->key = k;
    new->prev =  NULL;
    new->next =  NULL;
    return new;
}
List * create_list(){
    List * l = malloc(sizeof(List));
    l->head =  NULL;
    l->tail = NULL;
    return l;
}
void add(List * l, Node * x){
    if(l->head==NULL) {
        l->head = x;
        l->tail = x;
    }
    else{
        x->next = l->head;
        l->head->prev = x;
        l->head = x;
    }
}

int main(){
    List * values  = create_list();
    for(int i = 0; i < 20000; i = i +1){
        add(values,create_node(i));
    }
    printf("fim");
}
