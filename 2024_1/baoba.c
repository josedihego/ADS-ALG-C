#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct Node{
    int key;
    struct Node * p;
    struct Node * left;
    struct Node * right;
}Node;

typedef struct  MyTree{
    Node * root;
}MyTree;

Node * create_node(int key){
    Node * n = malloc(sizeof(Node));
    n->key = key;
    n->p = NULL;
    n->left = NULL;
    n->right = NULL;
    return n;
}

MyTree * create_tree(Node * root){
    MyTree * mt =  malloc(sizeof(MyTree));
    mt->root =  root;
    return mt;
}
