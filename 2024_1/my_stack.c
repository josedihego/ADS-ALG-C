#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define MIN_SIZE 10

typedef struct MyStack{
    int * S;
    int top;
    int size;
}MyStack;

void init(MyStack * my_stack){
    my_stack->size = MIN_SIZE;
    my_stack->S = (int *)malloc(my_stack->size * sizeof(int));
    my_stack->top = -1;
}
bool is_full(MyStack * my_stack){
    return my_stack->top == my_stack->size-1;
}
bool is_empty(MyStack * my_stack){
    return my_stack->top == -1;
}
void push(MyStack * my_stack, int x){
    if(!is_full(my_stack)){
    my_stack-> top = my_stack->top + 1;
    my_stack->S[my_stack->top] = x;
    }
    else{
        printf("Stack is full!\n");
    }
}
int pop(MyStack * my_stack){
    if(!is_empty(my_stack)){
        my_stack->top =  my_stack->top -1;
        return my_stack->S[my_stack->top + 1];
    }
    else return INT_MIN;
}
void print_stack(MyStack * my_stack){
    printf("top\n");
    for(int i = my_stack->top; i >= 0 ; i = i-1){
        printf("[%d]\n",my_stack->S[i]);
    }
    printf("botton\n");
}

int main(){
    MyStack * nb = (MyStack *)malloc(sizeof(MyStack));
    init(nb);
    push(nb,40);
    push(nb,12);
    push(nb,10);
    push(nb,15);
    push(nb,40);
    push(nb,22);
    pop(nb);
    print_stack(nb);
    free(nb->S);
    free(nb);
    return EXIT_SUCCESS;
}