#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
typedef struct Vertex
{
    char id; // identificador
    struct Vertex *pi;
    int d;
} Vertex;

typedef struct Edge
{
    Vertex *u; // origem
    Vertex *v; // destino
    int w;     // peso da aresta
} Edge;

typedef struct Graph
{
    Vertex **V;
    Edge **E;
    int n_V;
    int n_E;
} Graph;

typedef struct Node
{
    Vertex *key;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct My_List
{
    Node *head;
} My_List;

Node *create_node(Vertex *key)
{
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

My_List *create_list()
{
    My_List *ml = malloc(sizeof(My_List));
    ml->head = NULL;
    return ml;
}
void insert_list(My_List *ml, Node *x)
{
    x->next = ml->head;
    if (ml->head != NULL)
    {
        ml->head->prev = x;
    }
    ml->head = x;
    x->prev = NULL;
}
void delete(My_List *l, Node *x)
{
    if (x->prev != NULL)
    {
        x->prev->next = x->next;
    } 
    else
    {
        l->head = x->next;
    }
    if (x->next != NULL)
    {
        x->next->prev = x->prev;
    }
    free(x);
}

void initialize_single_source(Graph *G, Vertex *s)
{
    for (int i = 0; i < G->n_V; i = i + 1)
    {
        G->V[i]->d = INT_MAX;
        G->V[i]->pi = NULL;
    }
    s->d = 0;
}

void relax(Vertex *u, Vertex *v, int w)
{
    if (u->d + w < v->d)
    {
        v->d = u->d + w;
        v->pi = u;
    }
}

Vertex * extract_min(My_List * Q){
    Node * x = Q->head;
    Node * y = x; // representa o menor
    while(x->next !=NULL){
        if(x->next->key->d < y->key->d){
            y = x->next;
        }
        x= x->next;
    }
    Vertex * result =  y->key;
    delete(Q,y);
    return result;
}

Vertex ** adj(Graph * G, Vertex * x){
    Vertex ** list = malloc(G->n_V * sizeof(Vertex *));
    int j = 0;
    for(int i =0; i < G->n_E; i = i +1){
        if(G->E[i]->u == x){
            list[j] = G->E[i]->v;
            j= j+1;
        }
    }
    list[j]=NULL;
    return list;
}

int calc_w(Graph * G, Vertex * u, Vertex *v){
    for(int i =0; i < G->n_E; i = i +1){
        if(G->E[i]->u==u && G->E[i]->v==v){
            return G->E[i]->w;
        }
    }
}

void dijkstra(Graph * G, Vertex * s){
    initialize_single_source(G,s);
    My_List * Q = create_list();
    for(int i = 0; i < G->n_V; i= i+1){
        insert_list(Q,create_node(G->V[i]));
    }
    while(Q->head!=NULL){
        Vertex * u = extract_min(Q);
        Vertex ** adjs = adj(G,u);
        int i = 0;
        while(adjs[i]!=NULL){
            relax(u,adjs[i],calc_w(G,u,adjs[i]));
            i = i +1;
        }

    }
}