#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
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

void remove(int key, ListIFBA * l){
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



int main(){

}