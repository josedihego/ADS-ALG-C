#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int key;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct MyList{
    Node * head;
}MyList;

void init_list(MyList * list){
   list->head = NULL;
}

Node * list_search(MyList * L, int k){
    Node * x = L->head;
    while(x!=NULL && x->key != k){
        x = x->next;
    }
    return x;
}

void list_insert(MyList * L, Node * x){
    x->next = L->head;
    if(L->head != NULL){
        L->head->prev = x;
    }
    L->head = x;
    x->prev = NULL;
}
void print_list(MyList * L){
    Node * x = L->head;
    printf("%s", "[NIL<->");
    while(x!=NULL){
        printf("%d",x->key);
        printf("%s", "<->");
        x = x->next;

    }
      printf("%s", "NIL]");
}

int main(){
    MyList * estoque = malloc(sizeof(MyList));
    init_list(estoque);

    for(int i =0; i < 10; i = i +1){
        Node * n = malloc(sizeof(Node));
        n->key = i;
        list_insert(estoque, n);
    }
    print_list(estoque);

    printf("%s", "Fim");
    return EXIT_SUCCESS;
}