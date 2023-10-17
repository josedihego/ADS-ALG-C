
#include<stdlib.h>
#include<stdio.h>

typedef struct NodeSimple{
    float  key;
    struct NodeSimple * next;
}NodeSimple;

typedef struct ListSimple{
  NodeSimple * head;
}ListSimple;


typedef struct Node{
    int key;
    struct  Node * next;
    struct  Node * prev;
    ListSimple * lits_simple;
} Node;

typedef struct List2Link{
    Node * head;

}List2Link;