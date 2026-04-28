#include <stdio.h>
#include <stdlib.h>

typedef struct Profile{
    char * public_link;
    char * name;
    struct ListIFBA * contacts;
}Profile;

typedef struct Node{
    int key;
    Profile * profile;
    struct Node * next;
    struct Node * prev;
}Node;

typedef struct ListIFBA{
    Node * head;
}ListIFBA;

ListIFBA * create_list(){
    ListIFBA * n = malloc(sizeof(ListIFBA));
    n->head = NULL;
    return n;
}

Node * create_node(int key){
    Node * n = malloc(sizeof(Node));
    n->key = key;
    n->next = NULL;
    n->prev = NULL;
}

void insert(ListIFBA * l, Node * n){
    if(l->head==NULL){
        l->head = n;
    }
    else{
        l->head->prev = n;
        n->next = l->head;
        l->head = n;
    }
}

Node * search(int key, ListIFBA * l){
    Node * x = l->head;
    while(x!=NULL && x->key != key ){
        x =  x->next;
    }
    return x;
}

void remove_list(int key, ListIFBA * l){
    Node * r = search(key, l);
    if(r!=NULL){
        if(r->prev==NULL){
            l->head = l->head->next;
            if(l->head!=NULL){
                l->head->prev = NULL;
            }
            
        }
        else if(r->next==NULL){
            r->prev->next = NULL;
        }
        else{
            r->next->prev = r->prev;
            r->prev->next = r->next;
        }
        free(r);

    }
}

void print_list(ListIFBA * l){
    printf("\n");
    Node * x = l->head;
    while(x!= NULL){
        printf("<- %d ->", x->key);
        x = x->next;
    }
    printf("\n");
}

int main(){
    ListIFBA * nova_lista = create_list();
    insert(nova_lista, create_node(8));
    insert(nova_lista, create_node(6));
    insert(nova_lista, create_node(5));
    remove_list(5,nova_lista);
    print_list(nova_lista);
}