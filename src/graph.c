#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include "graph.h"

struct graph {
    uint32_t n_edges;
    uint32_t n_vertices;
    llist **array_vertices;
};

llist **allocate_matrix(uint32_t n_vertices) 
{
    llist **matrix;

    matrix = malloc(sizeof(llist *) * n_vertices);
    if (matrix == NULL) 
        return NULL;
 
    for(uint32_t i = 0; i < n_vertices; i++) {
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

graph *Graph_Create(uint32_t n_vertices) 
{
    graph *self = malloc(sizeof(graph));
    self->n_edges = 0;
    self->n_vertices = n_vertices;
    self->array_vertices = allocate_matrix(n_vertices);

    if(self->array_vertices == NULL) {
        free(self);
        return NULL;
    } else {
        return self;
    }
}

void Graph_Destroy(graph *self) 
{
    for(uint32_t i = 0; i < self->n_vertices; i++) 
        LinkedList_Destroy(self->array_vertices[i]);
    free(self->array_vertices);
    free(self);
}

void Graph_InsertEdge(graph *self, uint32_t source, uint32_t destiny) 
{   
    llist *s = self->array_vertices[source];
    llist *d = self->array_vertices[destiny];

    LinkedList_Prepend(s, destiny);
    LinkedList_Prepend(d, source);
}

void Graph_Show(graph *self)
{
    printf("Begin Graph:\n");
    for(uint32_t i = 0; i < self->n_vertices; i++) {
        printf("V[%d]", i);
        LinkedList_Show(self->array_vertices[i]);
    }
    printf("End Graph.\n");
}

bool Graph_IsConnected(graph *self)
{
    llist *queue = LinkedList_Create();
    bool visited[self->n_vertices];

    for(uint32_t i = 1; i < self->n_vertices; i++) 
        visited[i] = false;
    
    visited[0] = true;
    LinkedList_Append(queue, 0);

    uint32_t actual_vertex;
    uint32_t *adjacents_actual_vertex;
    while(LinkedList_IsEmpty(queue) == false) {
        actual_vertex = LinkedList_Shift(queue);
        adjacents_actual_vertex = LinkedList_Array(self->array_vertices[actual_vertex]);
        for(uint32_t i = 0; i < LinkedList_GetSize(self->array_vertices[actual_vertex]); i++ ) {
            uint32_t adjacent = adjacents_actual_vertex[i];
            if (visited[adjacent] == false) {
                visited[adjacent] = true;
                LinkedList_Append(queue, adjacent);
            }
        }
    }

    for(uint32_t i = 0; i < self->n_vertices; i++) {
        if(visited[i] == false) {
            return false;
        }
    }
    return true;
}