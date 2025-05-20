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

void insert_list(List_if * list, Node * new){
    if(list->head==NULL){
        list->head = new;
    }
    else{
        //list->head = new;
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
        
    }
}
void remove_list(List_if * list, int key){
    Node * x = list->head;
    while(x!=NULL && key != x->key){
        x = x->next;
    }
    if(x!=NULL){
        if(x==list->head){
            list->head = list->head->next;
            if(list->head!=NULL) list->head->prev = NULL;
            free(x);
        }
    }
}

int main(){
    List_if * idades = init_list();

    insert_list(idades, init_node(20));
    insert_list(idades, init_node(37));
    insert_list(idades, init_node(18));

    insert_list(idades, init_node(40));
    insert_list(idades, init_node(18));
    insert_list(idades, init_node(-1));
    /*
    Node *  no_joao = init_node(20);
    idades->head = no_joao;

    Node * no_rodrigo = init_node(37);
    no_joao->next = no_rodrigo;
    no_rodrigo->prev = no_joao;

    Node * no_julio = init_node(18);
    no_rodrigo->next = no_julio;
    no_julio->prev = no_rodrigo;
  */
    print_list(idades);

}