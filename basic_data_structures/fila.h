typedef struct {
  int *values;
  int head;
  int tail;
}Queue;

void enqueue(Queue * q, int x);
int dequeue(Queue * q);

int isEmpty(Queue * q);
int isFull(Queue * q);

void printQueue(Queue * q);
void init(Queue * q);
