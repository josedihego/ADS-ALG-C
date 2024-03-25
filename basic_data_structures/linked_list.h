typedef struct Node
{
   struct Node * prev;
   struct Node * next;
   int data;
   int d;        
}Node;

typedef struct List
{
  struct Node * head;     
}List;

void insertL(List * L, Node* x);
void removeL (List * L, Node* x);
Node * searchL(List * L, int data);

void printL(List * L);

void init(List * L);


