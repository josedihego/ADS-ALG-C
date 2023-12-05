#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~Graph part~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct Vertex
{
    char *key;
    int d;
    struct Vertex *prev;
} Vertex;

typedef struct Edge
{
    Vertex *src;
    Vertex *dst;
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
    e->dst = destination;
    e->src = source;
    e->w = w;
    return e;
}

void initialize_single_source(Graph *G, Vertex *s)
{
    for (int i = 0; i < G->nV; i = i + 1)
    {
        G->V[i]->d = INT_MAX;
        G->V[i]->prev = NULL;
    }
    s->d = 0;
}

int w(Vertex *u, Vertex *v, Graph *G)
{
    int i = 0;
    while (i < G->nE)
    {
        if (G->E[i]->src == u && G->E[i]->dst == v)
            return G->E[i]->w;
        i = i + 1;
    }
    return -1;
}

void relax(Vertex *u, Vertex *v, Graph *G)
{
    if (v->d > u->d + w(u, v, G))
    {
        v->d = u->d + w(u, v, G);
        v->prev = u;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~PriorityList part~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct Node
{
    Vertex *vrt;
    struct Node *next;
} Node;

typedef struct PriorityList
{
    Node *head;
} PriorityList;

void init_node(Node *node)
{
    node->next = NULL;
}
void init_list(PriorityList *list)
{
    list->head = NULL;
}

void insert_list(PriorityList *list, Node *node)
{
    node->next = list->head;
    list->head = node;
}

Node *extract_min(PriorityList *list)
{
    if (list->head == NULL)
        return NULL;
    Node *min = list->head;
    Node *x = list->head->next;
    while (x != NULL)
    {
        if (x->vrt->d < min->vrt->d)
        {
            min = x;
        }
        x = x->next;
    }
    remove_list(list, min);
    return min;
}

PriorityList *create_list_from_graph(Graph *G)
{
    PriorityList *list = malloc(sizeof(PriorityList));
    init_list(list);
    for (int i = 0; i < G->nV; i = i + 1)
    {
        Node *n = malloc(sizeof(Node));
        init_node(n);
        n->vrt = G->V[i];
        insert_list(list, n);
    }
    return list;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~dijkstra~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void dijkstra(Graph *G, Vertex *s)
{
    initialize_single_source(G, s);
    PriorityList *Q = create_list_from_graph(G);
    while (Q->head != NULL)
    {
        Vertex *u = extract_min(Q)->vrt;
        for (int i = 0; i < G->nE; i = i + 1)
        {
            if (G->E[i]->src == u)
            {
                Vertex *v = G->E[i]->dst;
                relax(u, v, G);
            }
        }
    }
    free(Q);
}

void print_distances(Graph *G, Vertex *s)
{
    for (int i = 0; i < G->nV; i = i + 1)
    {
        printf("The shortest path between %s and %s is: %d\n", s->key, G->V[i]->key, G->V[i]->d);
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~tests~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{

    Graph *graph = malloc(sizeof(Graph));
    graph->nV = 5;
    graph->nE = 10;
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

    dijkstra(graph, s);
    print_distances(graph, s);
    return EXIT_SUCCESS;
}