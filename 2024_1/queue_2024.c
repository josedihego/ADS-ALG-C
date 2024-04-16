#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyKiwi
{
    int *Q;
    int head;
    int tail;
    int length;
} MyKiwi;

void init(MyKiwi *mk, int length)
{
    mk->length = length;
    mk->Q = malloc(length * sizeof(int));
    mk->tail = 0;
    mk->head = 0;
}

void print_kiwi(MyKiwi *mk)
{
    int i = mk->head;
    printf("[(h)");
    while (i != mk->tail)
    {
        if (i != mk->tail - 1)
            printf(" %d,", mk->Q[i]);
        else
            printf(" %d", mk->Q[i]);

        i = (i + 1) % mk->length;
    }
    printf(" (t)]\n");
}

void enqueue(MyKiwi *mk, int x)
{
    mk->Q[mk->tail] = x;
    mk->tail = (mk->tail + 1) % mk->length;
}

int dequeue(MyKiwi *mk)
{
    int x = mk->Q[mk->head];
    mk->head = (mk->head + 1) % mk->length;
    return x;
}

int main()
{
    MyKiwi *f = malloc(sizeof(MyKiwi));
    init(f, 5);
    enqueue(f, 56);
    enqueue(f, 34);
    enqueue(f, 67);
    enqueue(f,25);
    dequeue(f);
    dequeue(f);
    enqueue(f,7);
    enqueue(f,9);
    print_kiwi(f);
    return EXIT_SUCCESS;
}