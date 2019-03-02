#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdint.h>
#include <stdbool.h>

typedef struct graph graph;

graph *Graph_Create(uint32_t max_n_vertices);
void Graph_Destroy(graph *self);

#endif // _GRAPH_H