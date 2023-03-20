#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void inOrderTreeWalk(Node * x)
{
   if(x!=NULL)
   {
         inOrderTreeWalk(x->left);
         printf(" %d ",x->key);
         inOrderTreeWalk(x->right);      
   }             
}
void preOrderTreeWalk(Node * x)
{
    if(x!=NULL) 
    {
    printf(" %d ",x->key);
    preOrderTreeWalk(x->left); 
    preOrderTreeWalk(x->right);
    }
}     
void postOrderTreeWalk(Node * x)
{
  if(x!=NULL)
  {
     postOrderTreeWalk(x->left);
     postOrderTreeWalk(x->right);
     printf(" %d ",x->key);         
  }             
}     

Node * treeSearch(Node * x, int key)
{ 
    if(x == NULL)
    {           
       return NULL;
    }
    else
    { 
        if(x->key == key)
        {
          return x;        
        }
        else{  
           if(key < x->key) 
           {
              return treeSearch(x->left, key);       
           }
           else
           {
              return treeSearch(x->right,key);
           }
       }         
    }               
}     
Node * iterativeTreeSearch(Node * x, int key)
{
     Node * temp = x;
     while(temp != NULL && temp->key != key)
     {
        if(key < temp->key)
        {
               temp = temp->left;
        }     
        else
        {
            temp = temp->right;
        }
     }
     return temp;  
}     

Node * treeMinimum(Node * x)
{
  Node * temp = x;
  while (temp->left != NULL)   
  {
        temp = temp->left;
  }
  return temp;
}     

Node * treeMaximum(Node * x){
 Node * temp = x;
 while(temp->right!=NULL)
 {
     temp = temp->right;                    
 }    
 return temp;
}
     
Node * treeSuccessor(Node * x)
{
     Node * y;
     Node * temp = x;
     
     if(x->right != NULL)
     {
       return treeMinimum(x->right);
     }
     y =  temp->p;
     while(y != NULL && temp ==  y->right)
     {
         temp = y;
         y = y->p;
             
     }
     return y;
}     
Node * treePredecessor(Node * x){
  Node * y;
  Node * temp = x;
  
  if(x->left != NULL)    
  {
     return treeMaximum(x->left);
  }
  y= temp->p;
  while(y != NULL && temp == y->left)
  {
     temp = y;
     y = y->p;
  }
  return y;        
}

void treeInsert(Tree * t, Node * z)
{
     Node * y = NULL;
     Node * x = t->root;
     while(x!= NULL)
     {
        y = x;
        if(z->key < x->key)
        {
          x =  x->left;         
        }       
        else
        {
            x= x->right;
        }    
     }
     z->p = y;
     if(y==NULL)
     {
        t->root = z;        
     }
     else{
       if(z->key < y->key)
       {
           y->left = z;      
       }              
       else
       {
           y->right = z;
       }
     }    
     
}
void treeDelete (Tree * t, Node * z)
{
     Node * y;
     Node * x;
     if(z->left == NULL || z->right == NULL)
     {
         y = z;       
     }
     else
     {
       y = treeSuccessor(z); 
     }
     
    if(y->left != NULL) 
    {
          x = y->left;     
    }
    else
    {
        x = y->right; 
    }
    
    if(x != NULL)
    {
         x->p = y->p;
    }
    
    if(y->p == NULL)
    {
            t->root = x;
    }
    else
    {
        if(y->p->left == y)
        {
           y->p->left = x;           
        }
        else
        {
           y->p->right = x;
        }
    }
    if(y != z)
    {
       z->key = y->key;  
    }
}


Node * createNode(int key)
{
     Node * res = malloc(sizeof(Node));
     initNode(res);
     res->key = key;
     return res;
}

Tree * createTree()
{
   Tree * res = malloc(sizeof(Tree));
   initTree(res);
   return res; 
}


void initNode(Node * n)
{
     n->p = NULL;
     n->left = NULL;
     n->right = NULL;
}
void initTree(Tree * t)
{
     t->root =  NULL;
}
