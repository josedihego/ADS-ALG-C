#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *p;
    struct Node *left;
    struct Node *right;
    int key;
} Node;

typedef struct Tree
{
    Node *root;
} Tree;

void inOrderTreeWalk(Node *x)
{
    if (x != NULL)
    {
        inOrderTreeWalk(x->left);
        printf(" %d ", x->key);
        inOrderTreeWalk(x->right);
    }
}
void preOrderTreeWalk(Node *x)
{
    if (x != NULL)
    {
        printf(" %d ", x->key);
        preOrderTreeWalk(x->left);
        preOrderTreeWalk(x->right);
    }
}
void postOrderTreeWalk(Node *x)
{
    if (x != NULL)
    {
        postOrderTreeWalk(x->left);
        postOrderTreeWalk(x->right);
        printf(" %d ", x->key);
    }
}

Node *treeSearch(Node *x, int key)
{
    if (x == NULL)
    {
        return NULL;
    }
    else
    {
        if (x->key == key)
        {
            return x;
        }
        else
        {
            if (key < x->key)
            {
                return treeSearch(x->left, key);
            }
            else
            {
                return treeSearch(x->right, key);
            }
        }
    }
}
Node *iterativeTreeSearch(Node *x, int key)
{
    while (x != NULL && x->key != key)
    {
        if (key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    return x;
}

Node *treeMinimum(Node *x)
{
    while (x->left != NULL)
    {
        x = x->left;
    }
    return x;
}

Node *treeMaximum(Node *x)
{
    while (x->right != NULL)
    {
        x = x->right;
    }
    return x;
}

Node *treeSuccessor(Node *x)
{
    Node *y;

    if (x->right != NULL)
    {
        return treeMinimum(x->right);
    }
    y = x->p;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->p;
    }
    return y;
}
Node *treePredecessor(Node *x)
{
    Node *y;
    if (x->left != NULL)
    {
        return treeMaximum(x->left);
    }
    y = x->p;
    while (y != NULL && x == y->left)
    {
        x = y;
        y = y->p;
    }
    return y;
}

void treeInsert(Tree *t, Node *z)
{
    Node *y = NULL;
    Node *x = t->root;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->p = y;
    if (y == NULL)
    {
        t->root = z;
    }
    else
    {
        if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
    }
}
void treeDelete(Tree *t, Node *z)
{
    Node *y;
    Node *x;
    if (z->left == NULL || z->right == NULL)
    {
        y = z;
    }
    else
    {
        y = treeSuccessor(z);
    }

    if (y->left != NULL)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if (x != NULL)
    {
        x->p = y->p;
    }

    if (y->p == NULL)
    {
        t->root = x;
    }
    else
    {
        if (y->p->left == y)
        {
            y->p->left = x;
        }
        else
        {
            y->p->right = x;
        }
    }
    if (y != z)
    {
        z->key = y->key;
    }
}

void initNode(Node *n)
{
    n->p = NULL;
    n->left = NULL;
    n->right = NULL;
}

void initTree(Tree *t)
{
    t->root = NULL;
}

Node *createNode(int key)
{
    Node *res = malloc(sizeof(Node));
    initNode(res);
    res->key = key;
    return res;
}

Tree *createTree()
{
    Tree *res = malloc(sizeof(Tree));
    initTree(res);
    return res;
}

int main(void)
{
    Tree *t = createTree();
    // arvore slide 18
    treeInsert(t, createNode(15));
    treeInsert(t, createNode(6));
    treeInsert(t, createNode(18));
    treeInsert(t, createNode(3));
    treeInsert(t, createNode(7));
    treeInsert(t, createNode(17));
    treeInsert(t, createNode(20));
    treeInsert(t, createNode(2));
    treeInsert(t, createNode(4));
    treeInsert(t, createNode(13));
    treeInsert(t, createNode(9));

    printf("%s", "\n----------------walks------------\n");
    inOrderTreeWalk(t->root);
    printf("%s", "\n");
    preOrderTreeWalk(t->root);
    printf("%s", "\n");
    postOrderTreeWalk(t->root);
    printf("%s", "\n");

    printf("%s", "\n----------------successor------------\n");
    printf("Successor 15 : %d \n", treeSuccessor(treeSearch(t->root, 15))->key);
    printf("Successor 13 : %d \n", treeSuccessor(treeSearch(t->root, 13))->key);
    printf("Successor 7 : %d \n", treeSuccessor(treeSearch(t->root, 7))->key);
    printf("Successor 20? : %s \n", treeSuccessor(treeSearch(t->root, 20)) == NULL ? "NO" : "YES");

    printf("%s", "\n----------------predecessor------------\n");
    printf("Predecessor 15 : %d \n", treePredecessor(treeSearch(t->root, 15))->key);
    printf("Predecessor 13 : %d \n", treePredecessor(treeSearch(t->root, 13))->key);
    printf("Predecessor 7 : %d \n", treePredecessor(treeSearch(t->root, 7))->key);
    printf("Predecessor 2? : %s \n", treePredecessor(treeSearch(t->root, 2)) == NULL ? "NO" : "YES");

    printf("%s", "\n----------------maximum e minumum------------\n");
    printf("Maximum : %d \n", treeMaximum(t->root)->key);
    printf("Minimum : %d \n", treeMinimum(t->root)->key);

    printf("%s", "\n----------------delete------------\n");
    treeDelete(t, iterativeTreeSearch(t->root, 6));
    inOrderTreeWalk(t->root);
    printf("%s", "\n");
    treeDelete(t, iterativeTreeSearch(t->root, 13));
    inOrderTreeWalk(t->root);
    printf("%s", "\n");
    treeDelete(t, iterativeTreeSearch(t->root, 20));
    inOrderTreeWalk(t->root);
    printf("%s", "\n");

    printf("%s", "\n----------------end------------\n");

    return EXIT_SUCCESS;
}
