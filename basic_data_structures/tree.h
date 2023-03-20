
typedef struct Node{
      struct Node * p;
      struct Node * left;
      struct Node * right;
      int key;  
}Node;


typedef struct Tree{
       Node * root; 
} Tree;        

void inOrderTreeWalk(Node * x);
void preOrderTreeWalk(Node * x);
void postOrderTreeWalk(Node * x);

Node * treeSearch(Node * x, int key);
Node * iterativeTreeSearch(Node * x, int key);
Node * treeMinimum(Node * x);
Node * treeMaximum(Node * x);
Node * treeSuccessor(Node * x);
Node * treePredecessor(Node * x);

void treeInsert(Tree * t, Node * z);
void treeDelete (Tree * t, Node * z);

Node * createNode(int key);
Tree * createTree();

void initNode(Node * n);
void initTree(Tree * t);


