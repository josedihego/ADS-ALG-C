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
  new_tree->root = NULL;
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

Node * tree_search(int key, My_Tree * t){
    Node * x = t->root;
    while(x!=NULL && x->key != key){
        if(key < x->key){
            x = x->left;
        }
        else{
            x= x->right;
        }
    }
    return x;
}
Node * tree_search_rec(int key, Node * x){
    if(x==NULL || x->key == key) return x;
    else{
        if(key < x->key) return tree_search_rec(key, x->left);
        else return tree_search_rec(key, x->right);
    }
}

Node * tree_minimum(Node * node){
    Node * x = node;
    while(x->left != NULL){
        x = x->left;
    }
    return x;
}

Node * tree_successor(Node * x){
    if(x->right != NULL){
        return tree_minimum(x->right);
    }
    Node * y = x;
    while(y != NULL && y->right != x){
        x = y;
        y = y->mother;
    }
    return y;
}

Node * tree_delete(My_Tree * T, Node * z){
    Node * y = NULL;
    Node * x = NULL;
    
    if(z->left==NULL || z->right == NULL) y = z;
    else y = tree_successor(z);
    
    if(y->left != NULL) x = y->left;
    else x = y->right;

    if(x!=NULL) x->mother = y->mother;

    if(y->mother == NULL) T->root = x;
    else{
        if(y== y->mother->left) y->mother->left = x;
        else y->mother->right = x;
    }
    if(y!=z) z->key = y->key;

    return y;
}



int main(){
    My_Tree * t = create_empty_tree();
    insert_tree(create_node(5),t);
    insert_tree(create_node(10),t);
    insert_tree(create_node(-1),t);
    insert_tree(create_node(3),t);
    insert_tree(create_node(4),t);
    inorder_tree_walk(t->root);
    printf("Resultados busca\n");

    int key_for_search = 3;
    Node * b1 = tree_search(key_for_search, t);
    if(b1!=NULL) printf("Achei: %d\n", b1->key);
    else printf("Não achei a chave %d\n",key_for_search);

    key_for_search = 100;
    Node * b2 = tree_search(key_for_search, t);
    if(b2!=NULL) printf("Achei: %d\n", b2->key);
    else printf("Não achei a chave: %d\n",key_for_search);


    key_for_search = 3;
    b1 = tree_search_rec(key_for_search, t->root);
    if(b1!=NULL) printf("Achei com rec: %d\n", b1->key);
    else printf("Não achei a chave com rec %d\n",key_for_search);

    key_for_search = 100;
    b2 = tree_search_rec(key_for_search, t->root);
    if(b2!=NULL) printf("Achei com rec: %d\n", b2->key);
    else printf("Não achei a chave com rec: %d\n",key_for_search);

    Node * node_3 = tree_search(3, t);
    Node * succ = tree_successor(node_3);
    printf("Sucessor do no %d é %d\n", node_3->key, succ->key);

}