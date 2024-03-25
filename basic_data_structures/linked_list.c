#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void insertL(List * L, Node* x)
{
     if(L->head != NULL){
     L->head->prev = x;
     }
     x->next = L->head;
     x->prev = NULL;
     L->head = x;
}


void removeL (List * L, Node* x)
{
     if(x->prev!=NULL){
     x->prev->next = x->next;
     }
     else{
          L->head = x->next;
     }
     if(x->next!=NULL){
     x->next->prev = x->prev;
     }
     free(x);
}     
Node * searchL(List * L, int data)
{
     Node* x = L->head;
     while(x!=NULL && x->data != data)
     {
        x = x->next;           
     }    
     return x;         
}


void printL(List * L){
    Node* x = L->head;
     while(x!=NULL)
     {
        printf("%d, ",x->data);           
        x = x->next;           
     } 
    printf("\n");    
}

void init(List * L){
  L->head = NULL;     
}
