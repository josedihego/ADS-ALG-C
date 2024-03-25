#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

#define A (sqrt(5)-1)/2
#define m 23

int fun_hash(int k){
   return (int)floor(m * (fmod(k * A, 1.0)));
}

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
void init_node(Node * node){
    node->prev = NULL;
    node->next =  NULL;
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

typedef struct HashTable{
     MyList ** hash;
     int size;
}HashTable;

void init_hash(HashTable * ht){
   ht->hash = malloc(ht->size * sizeof(MyList *)); 
   for(int i= 0 ; i < ht->size; i = i +1){
    ht->hash[i] = malloc(sizeof(MyList));
    init_list(ht->hash[i]);
   }
}



// ht: hashTable  k: chave (key)
void insert_hash(HashTable * ht, int k){
    //p : posição
    int p = fun_hash(k);
    Node * new_node = malloc(sizeof(Node));
    //init_node(new_node);
    new_node->key = k;
    list_insert(ht->hash[p],new_node);
}

int main(){
    HashTable * ht = malloc(sizeof(HashTable));
    ht->size =  m;
    init_hash(ht);

    for(int i =0; i < 200; i = i + 1){
           insert_hash(ht,i);
    }
    for(int i=0; i < ht->size; i = i + 1){
        printf("\nhash[%d]\n",i);
        print_list(ht->hash[i]);
    }
    return EXIT_SUCCESS;
}