#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

//#include "..\include\Sales_data.h"

int main(void)
{

    Queue * q = malloc(sizeof(Queue));
    init(q);
    printQueue(q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    printQueue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);
    printf("%s","-----\n");
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    dequeue(q);
    enqueue(q,0);
    printQueue(q);
    system("PAUSE");
}
