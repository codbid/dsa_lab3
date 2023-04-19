#pragma once

typedef struct edge
{
    int src;
    int dest;
    int value;
} edge;

void edge_add(struct edge *edges[], int src, int dest, int index, int value);