#include<stdio.h>
#include "llist.h"
#include "graph.h"

int main(void) {
  graph *exemplo = Graph_Create(20);
  if (exemplo == NULL) {
    printf("Memory allocation failed");
    return 1;
  }


  Graph_Destroy(exemplo);
  return 0;
}
