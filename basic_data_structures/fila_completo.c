#include <stdlib.h>
#include <stdio.h>


#define MAX  5

typedef struct
{
    int *values;
    int head;
    int tail;
} Queue;


int isFull(Queue *q)
{
    if (
        ((q->tail + 1) == q->head) ||
        (q->tail == (MAX - 1) && q->head == 0))
        return 1;
    else
        return 0;
}

int isEmpty(Queue *q)
{
    if (q->head == q->tail)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int x)
{
    if (!isFull(q))
    {
        q->values[q->tail] = x;
        if (q->tail == (MAX - 1))
        {
            q->tail = 0;
        }
        else
        {
            q->tail = q->tail + 1;
        }
    }
    else
    {
        printf("%s", "Fila cheia \n");
    }
}
int dequeue(Queue *q)
{
    int res;
    if (!isEmpty(q))
    {
        res = q->values[q->head];
        if (q->head == (MAX - 1))
        {
            q->head = 0;
        }
        else
        {
            q->head = q->head + 1;
        }
        return res;
    }
    else
    {
        printf("%s", "Fila vazia\n");
    }
}

void printQueue(Queue *q)
{
    int fim = 0;
    if (!isEmpty(q))
    {
        int i = q->head;
        while (!fim)
        {
            printf("%d ", q->values[i]);
            if (i == (MAX)-1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
            if (i == q->tail)
                fim = 1;
        }
        printf("%c", '\n');
    }
    else
    {
        printf("%s", "Fila vazia \n");
    }
}
void init(Queue *q)
{
    q->head = q->tail = 0;
    q->values = malloc(MAX * sizeof(int));
}

int main(void)
{

    Queue *q = malloc(sizeof(Queue));
    init(q);
    printQueue(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printQueue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);
    printf("%s", "-----\n");
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    dequeue(q);
    enqueue(q, 0);
    printQueue(q);
    return EXIT_SUCCESS;
}
