#define INT_MAX 2147483646

#include "minheap.h"

int ShortestPathDijekstra(struct heap *h, const int count, int src, int **matrix, int D[], int prev[]);