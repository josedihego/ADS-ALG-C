#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct Node{
    int key;
    struct Node * left;
    struct Node * right;
    struct Node * mother;
}Node;

typedef struct My_Tree{
    Node * root;
}My_Tree;

Node * create_node(int key){
    Node * new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->mother = NULL;
    return new_node;
}

My_Tree * create_empty_tree(){
  My_Tree * new_tree = malloc(sizeof(My_Tree));
  return new_tree;
}

My_Tree * create_tree(Node * root){
  My_Tree * new_tree = malloc(sizeof(My_Tree));
  new_tree->root = root;
  return new_tree;
}

void insert_tree(Node * node, My_Tree * tree){
    if(tree->root == NULL) tree->root = node;
    else{
        Node * sacrifice = tree->root;
        Node * mother;
        while(sacrifice!=NULL){
            mother = sacrifice;
            if(node->key < sacrifice->key){
                sacrifice =  sacrifice->left;
            }
            else{
                sacrifice = sacrifice->right;
            }
        }
        if(node->key < mother->key){
            mother->left = node;
        }
        else{
            mother->right = node;
        }
        node->mother = mother;
    }
}

void inorder_tree_walk(Node * node){
    if(node!=NULL){
        inorder_tree_walk(node->left);
        printf(" %d", node->key);
        inorder_tree_walk(node->right);
    }
}

int main(){
    My_Tree * t = create_empty_tree();
    insert_tree(create_node(5),t);
    insert_tree(create_node(10),t);
    insert_tree(create_node(-1),t);
    insert_tree(create_node(3),t);
    insert_tree(create_node(4),t);
    inorder_tree_walk(t->root);
}