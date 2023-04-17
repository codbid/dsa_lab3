#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link.h"

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

void edge_add(struct edge *edges[], int src, int dest, int index)
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
    node->value = getrand(1, 10);
    edges[index] = node;
}

int check(struct edge *edges[], int edges_count, int src, int dest)
{
    int final = 0;
    for (int j = 0; j < edges_count; j++)
    {
        struct edge *current_egde = edges[j];
        if ( current_egde->src == src )
        {
            if ( current_egde->dest == dest )
                return 1;
            final = check(edges, edges_count, current_egde->dest, dest); 
        }
        if ( final )
            return 1;
    }
    return 0;
}

int check_all(struct edge *edges[], int edges_count)
{
    int linked = 1;
    for ( int i = 1; i < LCOUNT; i++ )
    {
        for ( int j = i + 1; j < LCOUNT; j++ )
        {
            if ( i != j )
            {
                linked *= check(edges, edges_count, i, j);
            }
        }
    }
    return linked;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct edge **generate_link(struct edge **edges, int *edges_count)
{
    for ( int i = 0; i < LCOUNT; i++ )
    {
        for ( int j = 0; j < LCOUNT; j++ )
        {
            int src = 0;
            int dest = 0;
            while (src == dest || check(edges, *edges_count, src, dest))
            {
                src = getrand(1, LCOUNT);
                dest = getrand(1, LCOUNT + 1);
                if ( src > dest )
                    swap(&src, &dest);
            }

            int include = 0;
            for ( int k = 0; k < *edges_count; k++ )
            {
                if ( edges[k]->src == src && edges[k]->dest == dest )
                    include = 1;
            }

            if ( !include )
            {
                edge_add(edges, src, dest, *edges_count);
                //printf("\n%d->%d\n", src, dest);
                *edges_count += 1; //  ??
                if ( check_all(edges, *edges_count) )
                    return edges;
            }
        }
    }
    printf("No");
}

void create_link_graph(int matrix[LCOUNT][LCOUNT], edge **edges, int *edges_count)
{
    generate_link(edges, edges_count);
    printf("Linked graph with %d vertices:\n", *edges_count);
    for ( int i = 0; i < LCOUNT; i++ )
    {
        for ( int j = 0; j < LCOUNT; j++ )
        {
            matrix[i][j] = 0;
        }
    }

    for ( int i = 0; i < *edges_count; i++ )
    {
        int src = edges[i]->src - 1;
        int dest = edges[i]->dest - 1;
        matrix[src][dest] = matrix[dest][src] = edges[i]->value;
    }
}