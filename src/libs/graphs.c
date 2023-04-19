#include <stdio.h>
#include <stdlib.h>

#include "graphs.h"

void edge_add(struct edge *edges[], int src, int dest, int index, int value)
{
    struct edge *node;
    node = malloc(sizeof(*node));
    if ( src < dest ) {
        node->src = src;
        node->dest = dest;
    }
    else 
    {
        node->src = dest;
        node->dest = src;
    }
    node->value = value;
    edges[index] = node;
}