#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "graph.h"

struct graph {
    uint32_t n_edges;
    uint32_t n_vertices;
    llist *array_vertices;
};

graph *Graph_Create(void) {
    graph *self = (graph *)malloc(sizeof(graph));
    self->n_edges = 0;
    self->n_vertices = 0;
    self->array_vertices = LinkedList_Create();

    return self;
}