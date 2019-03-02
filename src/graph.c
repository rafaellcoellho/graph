#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "graph.h"

struct graph {
    uint32_t n_edges;
    uint32_t n_vertices;
    uint32_t max_n_vertices;
    llist **array_vertices;
};

llist **allocate_matrix(uint32_t max_n_vertices) {
    llist **matrix;

    matrix = malloc(sizeof(llist *) * max_n_vertices);
    if (matrix == NULL) 
        return NULL;
 
    for(uint32_t i = 0; i < max_n_vertices; i++) {
        matrix[i] = LinkedList_Create();
        if (matrix[i] == NULL) {
            for(uint32_t j= 0; j<i; j++) 
                LinkedList_Destroy(matrix[j]);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

graph *Graph_Create(uint32_t max_n_vertices) {
    graph *self = malloc(sizeof(graph));
    self->n_edges = 0;
    self->n_vertices = 0;
    self->max_n_vertices = max_n_vertices;
    self->array_vertices = allocate_matrix(max_n_vertices);

    if(self->array_vertices == NULL) {
        free(self);
        return NULL;
    } else {
        return self;
    }
}

void Graph_Destroy(graph *self) {
    for(uint32_t i = 0; i < self->max_n_vertices; i++) 
        LinkedList_Destroy(self->array_vertices[i]);
    free(self->array_vertices);
    free(self);
}