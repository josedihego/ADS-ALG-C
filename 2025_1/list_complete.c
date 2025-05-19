#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int key;
    struct Node * prev;
    struct Node * next;
}Node;

typedef struct List_if{
    Node * head;
}List_if;


Node * init_node(int key){
    Node * node = malloc(sizeof(Node));
    node->key = key;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

List_if * init_list(){
    List_if * list = malloc(sizeof(List_if));
    list->head = NULL;
    return list;
}

void print_list(List_if * list){
    Node * x = list->head;
    printf("\n(NULL)");
    while(x!=NULL){
        printf("<- (%d) ->", x->key);
        x = x->next;
    }
    printf(" (NULL)\n\n");
}

int main(){
    List_if * idades = init_list();

    Node *  no_joao = init_node(20);
    idades->head = no_joao;

    Node * no_rodrigo = init_node(37);
    no_joao->next = no_rodrigo;
    no_rodrigo->prev = no_joao;

    Node * no_julio = init_node(18);
    no_rodrigo->next = no_julio;
    no_julio->prev = no_rodrigo;

    print_list(idades);

}