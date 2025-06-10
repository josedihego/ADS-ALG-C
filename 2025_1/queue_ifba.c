#include <stdio.h>
#include <stdlib.h>


typedef struct Queue_I{
    int * Q;
    int size;
    int head;
    int tail;
}Queue_I;

void init_queue(Queue_I * queue,  int size){
    queue->size =  size;
    queue->Q = (int *)malloc(size * sizeof(int));
    queue->head = queue->tail = 0;
}

void enqueue(Queue_I * queue, int x){
    queue->Q[queue->tail] = x;
    if(queue->tail == queue->size-1){
        queue->tail = 0;
    }
    else{
        queue->tail = queue->tail + 1;
    }
    // queue->tail = (queue->tail + 1) % queue->size;
}

int dequeue(Queue_I * queue){
    int x = queue->Q[queue->head];
    if(queue->head==queue->size-1){
        queue->head = 0;
    }
    else{
        queue->head = queue->head +1;
    }
}

void print_queue()

int main(){

}