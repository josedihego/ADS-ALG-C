#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

#define MAX_SIZE  100

typedef struct Queue{
   float * Q;
   int head;
   int tail;
}Queue;

void init(Queue * q){
    q->head = q->tail = 0;
    q->Q = malloc(MAX_SIZE * sizeof(float));
}
 void enqueue(Queue * q, float x){
    q->Q[q->tail] = x;
    if(q->tail == MAX_SIZE-1) q->tail = 0;
    else q->tail = q->tail + 1;
 }
 void print_queue(Queue * q){
    int i = q->head;
    int j= q->tail;
    printf("%s", "[");
    while(i != j){
        if(i==j-1) printf("%.2f", q->Q[i]);
        else printf("%.2f, ", q->Q[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%s\n", "]");
 }

int main(){
    Queue * f  = malloc(sizeof(Queue));
    init(f);
    enqueue(f, 3.4);
    enqueue(f, 8.2);
    enqueue(f, 9.5);
    print_queue(f);
    return EXIT_SUCCESS;
}