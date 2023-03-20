#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

int MAX =5;

void enqueue(Queue* q, int x)
{    
     if(!isFull(q)){ 
     q->values[q->tail]= x;
      if(q->tail==(MAX -1)){
        q->tail= 0;
      }
      else{
         q->tail = q->tail+1;
      }
     }
     else{
        printf("%s","Fila cheia \n");  
     }
}
int dequeue(Queue* q)
{
    int res;
    if(!isEmpty(q)){
      res = q->values[q->head];
       if(q->head==(MAX-1)){
         q->head=0;               
       }          
       else{ 
         q->head = q->head +1;  
       }
      return res;
    }
    else{
         printf("%s","Fila vazia\n");
    }
}

int isEmpty(Queue* q){
  if(q->head == q->tail)
   return 1;
  else return 0;
}
int isFull(Queue* q){
  if(
   ((q->tail + 1)== q->head) ||
   (q->tail == (MAX-1) && q->head == 0)
   )
   return 1;
  else return 0; 
}

void printQueue(Queue* q){
 int fim = 0;
 if(!isEmpty(q)){
 int i = q->head;
 while(!fim){
  printf("%d ",q->values[i]);
  if(i==(MAX)-1){
      i=0;           
  }
  else{
       i++;
  }
  if(i==q->tail) fim=1;            
 }
 printf("%c",'\n');
}
else{
   printf("%s","Fila vazia \n");    
}

}
void init(Queue* q){
  q->head = q->tail =0;
  q->values = malloc(MAX*sizeof(int));  
}

