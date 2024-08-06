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

MyTree * create_empty_tree(){
    MyTree * mt =  malloc(sizeof(MyTree));
    mt->root = NULL;
    return mt;
}

void insert_tree(MyTree * t, Node * x){
    if(t->root == NULL){
        t->root = x;
    }
    else{
        Node * y = t->root;
        Node * smart;
        while(y!=NULL){
            smart = y;
            if(x->key > y->key){
                y = y -> right;
            }
            else{
                y= y->left;
            }
        }
        if(x->key > smart->key){
            smart->right = x;
        }
        else{
            smart->left = x;
        }
        x->p = smart;

    }
}
int main(){
    /**
    MyTree * ar_pass = create_tree(create_node(56));
    Node * no_45 = create_node(45);
    ar_pass->root->left = no_45;
    no_45->p = ar_pass->root;
    Node * no_70 = create_node(70);
    ar_pass->root->right = no_70;
    no_70->p =  ar_pass->root;
    printf("Fim");
    * 
     */
    MyTree * ar_pass = create_empty_tree();
    insert_tree(ar_pass, create_node(30));
    insert_tree(ar_pass, create_node(79));
    insert_tree(ar_pass, create_node(56));
    insert_tree(ar_pass, create_node(21));
    insert_tree(ar_pass, create_node(30));
    printf("Fim");

}


