#include <stdio.h>

#include "dijekstra.h"
#include "minheap.h"

int ShortestPathDijekstra(struct heap *h, const int count, int src, int **matrix, int D[], int prev[])
{
    int H[count+1];
    int removed = 0;
    H[src] = 0;
    D[src] = 0;
    prev[src] = -1;
    heap_insert(h, D[src], src);
    for ( int i = 1; i < count + 1; i++ )
    {
        if ( i != src )
        {
        H[i] = 0;
        D[i] = INT_MAX;
        prev[i] = -1;
        heap_insert(h, D[i], i);
        }
    }
   

    for ( int i = 1; i < count + 1; i++ )
    {
        struct heapnode v = heap_extract_min(h);
        removed++;
        H[v.value] = v.value;
        int vertex = v.value;
    

        for ( int j = 1; j < count + 1; j++ )
        {
            if ( matrix[vertex-1][j-1] && ! H[j] )
            {
                if ( D[vertex] + matrix[vertex-1][j-1] < D[j] && D[vertex] != INT_MAX )
                {
                    int index = j;
                    if ( index != h->nodes[j].value || index >= h->nnodes )
                    {
                        for ( int k = 1; k < h->nnodes + 1; k++ )
                        {
                            if ( h->nodes[k].value == j )
                            {
                                index = k;
                                break;
                            }
                        }
                    }
                    D[j] = D[vertex] + matrix[vertex-1][j-1];
                    heap_decrease_key(h, index, D[j]);
                    prev[j] = vertex;
                }
            }
        }
    }
}