#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdint.h>
#include <stdbool.h>

typedef struct graph graph;

graph *Graph_Create(uint32_t max_n_vertices);
void Graph_Destroy(graph *self);
void Graph_InsertEdge(graph *self, uint32_t source, uint32_t destiny);
void Graph_Show(graph *self);
bool Graph_IsConnected(graph *self);

#endif // _GRAPH_H