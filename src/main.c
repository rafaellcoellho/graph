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

  Graph_InsertEdge(exemplo, 1, 2);
  Graph_Show(exemplo);

  Graph_Destroy(exemplo);
  return 0;
}
