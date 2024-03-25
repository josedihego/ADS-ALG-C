
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
     int key;
     struct Node * left;
     struct Node * right;
     struct Node * m;
} Node;

typedef struct Tree{
    Node * root;
}Tree;

Node  * create_node(int key){
   Node * node = malloc(sizeof(Node));
   node->key =  key;
   return node; 
}

void inorder_tree_walk(Node * x){
    if(x!= NULL){
        inorder_tree_walk(x->left);
        printf(" %d ", x->key);
        inorder_tree_walk(x->right);
    }
}
void tree_insert(Tree * T, Node * z){
    Node * y = NULL;
    Node * x = T->root;
    while(x != NULL){
        y  = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->m = y;
    if(y== NULL) T->root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z; 
}

Node * tree_search(Node * x, int k){
    if(x==NULL || k == x->key) return x;
    if(k < x->key) return tree_search(x->left, k);
    else return tree_search(x->right, k);
}

Node * tree_ite_search(Tree * T, int k){
    Node * x = T->root;
    while(x!=NULL && k!= x->key){
        if(k < x->key) x =  x->left;
        else x =  x->right;
    }
    return x;
}

Node * tree_minimum(Node * x){
    if(x->left == NULL) return x;
    else return tree_minimum(x->left);
}

Node * tree_successor(Node * x){
    if(x->right != NULL){
        return tree_minimum(x->right);
    }
    Node * y = x->m;
    while(y!= NULL  && x == y->right){
        x = y;
        y = y->m;
    }
    return y;
}

// do livro
Node * tree_delete(Tree * T, Node * z){
    Node * y;
    Node * x;
    if(z->left == NULL || z->right == NULL) y = z;
    else y = tree_successor(z);
    if(y->left != NULL) x = y->left;
    else x = y->right;
    if(x!=NULL) x->m = y->m;
    if(y->m == NULL) T->root = x;
    else{
        if(y == y->m->left) y->m->left =  x;
        else y->m->right = x;
    }
    if(y!=z) z->key = y->key;
    return y;
}
void tree_delete2(Tree * T, Node * z){
    Node * y;
    Node * x;
    if(z->left == NULL || z->right == NULL) y = z;
    else y = tree_successor(z);
    if(y->left != NULL) x = y->left;
    else x = y->right;
    if(x!=NULL) x->m = y->m;
    if(y->m == NULL) T->root = x;
    else{
        if(y == y->m->left) y->m->left =  x;
        else y->m->right = x;
    }
    if(y!=z) z->key = y->key;
    free(y);
}

void printTree(Node* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 5;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    // Process left child
    printTree(root->left, space);
}

//  Node * y = tree_delete(T,z)
//  free(y)

// free(tree_delete(T,z))

int main(){
   Tree * arvore_anos = malloc(sizeof(Tree));
   Node * n1 = create_node(1960);
   Node * n2 = create_node(2001);
   Node * n3 = create_node(1939);
   tree_insert(arvore_anos,n1);
   tree_insert(arvore_anos,n2);
   tree_insert(arvore_anos,n3);
   tree_insert(arvore_anos, create_node(1990));
   tree_insert(arvore_anos, create_node(1986));
   tree_insert(arvore_anos, create_node(1959));
   Node * n_1988;
   tree_insert(arvore_anos, (n_1988 = create_node(1988)));
   tree_insert(arvore_anos, create_node(2001));
   tree_insert(arvore_anos, create_node(4567));
   inorder_tree_walk(arvore_anos->root);

   Node * rb = tree_ite_search(arvore_anos,1988);
   if(rb==NULL) printf("\n Nó não encontrado\n");
   else printf("\n No encontrado: chave %d\n", rb->key);

   Node * suc_1988 = tree_successor(n_1988);
   printf("Sucessor do 1988 é: %d", suc_1988->key);

   Node * suc_n2_2001_p1 = tree_successor(n2);
   printf("Sucessor do 2001 p1 é: %d", suc_n2_2001_p1->key);
 
  
   printTree(arvore_anos->root,5);
   tree_delete2(arvore_anos,arvore_anos->root);
   printf("%s\n", "Depois da remoção da raiz:");
   printTree(arvore_anos->root,5);

   /*
   arvore_anos->root = n1;

   n1->m = NULL;
   n1->left = n3;
   n1->right = n2;
   n2->m = n1;
   n2->left = NULL;
   n2->right =  NULL;
   n3->m = n1;
   n3->left = NULL;
   n3->right =  NULL;
   */
   return EXIT_SUCCESS;
}