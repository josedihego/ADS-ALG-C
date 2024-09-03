#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>


typedef struct Vertex
{
    bool visited;
    char key;
    int length;
    struct Vertex * pred;
}Vertex;

typedef struct Edge{
   Vertex * o;
   Vertex * d;
   int weight;
}Edge;

typedef struct Graph{ 
   int size_V;
   int size_E;
   Vertex ** V;
   Edge ** E;
}Graph;


void initialize_single_source(Graph * G, Vertex * s){
    for(int i =0; i < G->size_V; i = i +1){
            G->V[i]->length = INT_MAX;
            G->V[i]->pred = NULL;
    }
    s->length = 0;
}

void relax(Vertex * u, Vertex * v, int w){
    if (v->length > u->length + w){
        v->length = u->length + w;
        v->pred = u;
    }
}

Vertex ** adj(Graph * G, Vertex * s){
    Vertex ** lv =  malloc(G->size_V * sizeof(Vertex *));
    int i_lv = 0;
    for(int i = 0; i < G->size_E; i = i +1){
        Edge * e = G->E[i];
        if(e->o == s){
            lv[i_lv] =  e->d;
            i_lv = i_lv + 1;
        }
    }
    return lv;
}

Vertex * extract_min(Vertex ** v, int size){
    Vertex * min = v[0];
    for(int i = 1; i < size; i = i +1){
        if(v[i]->length < min->length && !v[i]->visited){
            min = v[i];
        }
    }
    return min;
}

bool all_visited(Vertex ** V, int tam){
    bool all_done = true;
    for(int i =0; i  < tam ; i = i +1){
        all_done = all_done && V[i]->visited;
    }
    return all_done;
}
void dijkstra(Graph * G, Vertex * s){
    initialize_single_source(G,s);
    Vertex ** Q = G->V;
    while (!all_visited(Q, G->size_V))
    {
        Vertex * u = extract_min(Q,G->size_V);
        
    }
    
}
