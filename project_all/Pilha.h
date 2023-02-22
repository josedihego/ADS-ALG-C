// (a)sem typedef...
typedef struct{
  int* values;
  int top;     
}Stack;

void push( Stack * s, int e);
int pop( Stack * s);

int isEmpty( Stack * s);
int isFull(Stack * s);

void printStack(Stack *s);
void init(Stack *s);
// (b)teria que usar struct Stack
