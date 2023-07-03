#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include "hash.h"

#define MAX  30

int h(int k){
  return (int)floor(30*(k*0.61 - floor(k*0.61)));    
}

void insertHash( Hash * hash, int k){
       int pos = h(k);
       
       Node * n = malloc(sizeof(Node));
       n->data = k;
       
       insertL(hash->T + pos,n);
}

void removeHash ( Hash * hash, Node * n)
{
     int pos = h(n->data);
     removeL(hash->T+pos,n);
     
}
Node * searchHash( Hash * hash, int k)
{
    int pos = h(k);
    return searchL(hash->T+pos,k) ; 
}

void printHash( Hash * hash)
{
  int i;   
  for(i=0;i < MAX ; i++)
   {
     printf("T[%d] ",i);
     printL(hash->T+i);       
     printf("%s","\n");  
   }
}     

void initHash( Hash * hash)
{
  int i;   
  hash->T = malloc(MAX * sizeof(List)); 
  for(i =0; i < MAX; i++) init(hash->T+i);   
}
