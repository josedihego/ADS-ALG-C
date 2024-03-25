#include <stdlib.h>
#include "my_stack.h"
int MAX = 5;

void push(Stack *s, int e)
{
     if (!isFull(s))
     {
          s->top = s->top + 1;
          s->values[s->top] = e;
     }
     else
     {
          printf("%s", "Pilha Cheia\n");
     }
}

int pop(Stack *s)
{
     if (!isEmpty(s))
     {
          s->top = s->top - 1;
          return s->values[s->top + 1];
     }
     else
     {
          printf("%s", "Pilha vazia\n");
     }
}

int isEmpty(Stack *s)
{
     if (s->top == -1)
          return 1;
     else
          return 0;
}

int isFull(Stack *s)
{
     if (s->top == (MAX - 1))
          return 1;
     else
          return 0;
}

void printStack(Stack *s)
{
     int i;
     if (!isEmpty(s))
     {
          for (i = 0; i <= s->top; i++)
          {
               printf("%d  ", s->values[i]);
          }
          printf("%s", "\n");
     }
     else
     {
          printf("%s", "Pilha Vazia\n");
     }
}
void init(Stack *s)
{
     s->top = -1;
     s->values = malloc(MAX * sizeof(int));
}
