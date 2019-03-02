#include<stdio.h>
#include "llist.h"
#include "graph.h"

int main(void) 
{
  graph *exemplo = Graph_Create(10);
  if (exemplo == NULL) {
    printf("Memory allocation failed");
    return 1;
  }

  Graph_InsertEdge(exemplo, 0, 1);
  Graph_InsertEdge(exemplo, 0, 4);
  Graph_InsertEdge(exemplo, 0, 6);

  Graph_InsertEdge(exemplo, 1, 4);
  Graph_InsertEdge(exemplo, 1, 6);

  Graph_InsertEdge(exemplo, 2, 6);

  Graph_InsertEdge(exemplo, 3, 5);
  Graph_InsertEdge(exemplo, 3, 7);
  Graph_InsertEdge(exemplo, 3, 9);

  Graph_InsertEdge(exemplo, 4, 6);

  Graph_InsertEdge(exemplo, 5, 7);
  Graph_InsertEdge(exemplo, 5, 8);
  Graph_InsertEdge(exemplo, 5, 9);

  Graph_InsertEdge(exemplo, 7, 8);

  Graph_InsertEdge(exemplo, 8, 9);

  Graph_Show(exemplo);

  printf("The graph is %s\n", Graph_IsConnected(exemplo) ? "Connected" : "Not Connected");

  Graph_Destroy(exemplo);
  return 0;
}
