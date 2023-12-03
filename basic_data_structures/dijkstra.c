#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct Vertex
{
    char *key;
    int d;
    int pi;
} Vertex;

typedef struct Edge
{
    Vertex *source;
    Vertex *destination;
    int w;
} Edge;


typedef struct Graph
{
    Vertex **V;
    Edge **E;
    int nE;
    int nV;
} Graph;

Vertex *create_vertex(char *key)
{
    Vertex *v = malloc(sizeof(Vertex));
    v->key = key;
    return v;
}
Edge *create_edge(Vertex *source, Vertex *destination, int w)
{
    Edge *e = malloc(sizeof(Edge));
    e->destination = destination;
    e->source = source;
    e->w = w;
    return e;
}

void initialize_single_source(Graph * graph, Vertex * s){
    for(int i = 0; i < graph->nV; i = i +1){
        graph->V[i]->d = INT_MAX;
        graph->V[i]->pi = NULL;
    }
}

int w(Vertex * u, Vertex * v, Graph * graph){
    int i = 0;
    while(i < graph->nE){
        if(graph->E[i]->source==u && graph->E[i]->destination==v) return graph->E[i]->w;
        i = i + 1;
    }
    return -1;
}

void relax(Vertex * u, Vertex * v, Graph * graph){
    if (v->d > u->d + w(u,v,graph)){
        v->d =  u->d + w(u,v,graph);
        v->pi = u;
    }
}




typedef struct Node{
    Vertex * key;
    Vertex * next;
}Node;

typedef struct PriorityList{
    Node * head;
}PriorityList;

void init_node(Node * node){
    node->next =  NULL;
}
void init_list(PriorityList * list){
    list->head =  NULL;
}

void insert_list(PriorityList * list, Node * node){
 if(list->head == NULL) list->head = node;
 else{
    Node * x = list->head;
    Node * y = NULL;
    while(x!= NULL && node->key->d > x->key->d){
        y = x;
        x =  x->next;
    }
     y->next = node;
     node->next = x; 
 }
}

Node * extract_min(PriorityList * list){
    Node * res =  list->head;
    list->head = list->head->next;
    return res;
}

PriorityList * extract_list(Graph * G){
    PriorityList * list = malloc(sizeof(PriorityList));
    init_list(list);
    for(int i = 0; i < G->nE; i = i +1){
        Node * n =  malloc(sizeof(Node));
        init_node(n);
        n->key = G->E[i];
        insert_list(list,n);
    }
}

void dijkstra(Graph * G,Vertex * s){
    initialize_single_source(G,s);
    PriorityList * Q =  extract_list(G);
    while (Q->head != NULL)
    {
        Node * u = extract_min(Q);
        
    }
    
}

int main()
{
  
    Graph *graph = malloc(sizeof(Graph));
    graph->nV = 5;
    graph->nE =  10;
    graph->V = malloc(graph->nV * sizeof(Vertex *));
    graph->E = malloc(graph->nE * sizeof(Edge *));

    Vertex *s = create_vertex("s");
    graph->V[0] = s;
    Vertex *t = create_vertex("t");
    graph->V[1] = t;
    Vertex *x = create_vertex("x");
    graph->V[2] = x;
    Vertex *y = create_vertex("y");
    graph->V[3] = y;
    Vertex *z = create_vertex("z");
    graph->V[4] = z;

    Edge *s_t = create_edge(s, t, 10);
    graph->E[0] = s_t;
    Edge *s_y = create_edge(s, y, 5);
    graph->E[1] = s_y;
    Edge *t_y = create_edge(t, y, 2);
    graph->E[2] = t_y;
    Edge *t_x = create_edge(t, x, 1);
    graph->E[3] = t_x;
    Edge *y_t = create_edge(y, t, 3);
    graph->E[4] = y_t;
    Edge *y_x = create_edge(y, x, 9);
    graph->E[5] = y_x;
    Edge *y_z = create_edge(y, z, 2);
    graph->E[6] = y_z;
    Edge *x_z = create_edge(x, z, 4);
    graph->E[7] = x_z;
    Edge *z_x = create_edge(z, x, 6);
    graph->E[8] = z_x;
    Edge *z_s = create_edge(z, s, 7);
    graph->E[9] = z_s;
}