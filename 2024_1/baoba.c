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

void remove_tree_node(MyTree * t, Node * x){
    if(x->left == NULL && x->right==NULL){
        Node * p = x->p;
        if(x->key < p->key){
            p->left = NULL;
        }
        else{
            p->right = NULL;
        }
    }
    else if(x->left==NULL ^ x->right==NULL){
        Node * c = x->left!=NULL? x->left : x->right;
        c->p = x->p;
        if(x->key < x->p->key){
            x->p->left = c;
        }
        else{
            x->p->right = c;
        }
    }
    free(x);
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
    Node * r15;
    Node * r10;
    MyTree * ar_pass = create_empty_tree();
    insert_tree(ar_pass, create_node(8));
    insert_tree(ar_pass, create_node(12));
    insert_tree(ar_pass, create_node(7));
    insert_tree(ar_pass, r10 = create_node(10));
    insert_tree(ar_pass, r15 = create_node(15));
    insert_tree(ar_pass, create_node(6));
    insert_tree(ar_pass, create_node(18));
    remove_tree_node(ar_pass,r15);
    remove_tree_node(ar_pass,r10);
    printf("Fim");

}


