#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "../libs/link.h"
#include "../libs/shell.h"
#include "../libs/graphs.h"
#include "../libs/minheap.h"
#include "../libs/dijekstra.h"


double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    //edge edges[COUNT * COUNT];
    struct edge *l_edges[LCOUNT * LCOUNT];
    int l_edges_count = 0;
    int** l_matrix = (int **)calloc(LCOUNT, sizeof(int *));
    for ( int i = 0; i < LCOUNT; i++ )
        l_matrix[i] = (int *)calloc(LCOUNT, sizeof(int));
    int **s_matrix = (int **)calloc(SCOUNT, sizeof(int *));
    for ( int i = 0; i < SCOUNT; i++ )
        s_matrix[i] = (int *)calloc(SCOUNT, sizeof(int));
    create_link_graph(l_matrix, l_edges, &l_edges_count);
    

    printf("Create linked graph with %d edges of random weight from 1 to 10 :\n\n", l_edges_count);
    for(int i = 0; i < LCOUNT; i++) {
        for(int j = 0; j < LCOUNT; j++) {
            printf("%d ", l_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    struct heap *h;
    h = heap_create(LCOUNT);
    int l_D[LCOUNT+1];
    int l_prev[LCOUNT+1];
    double start = wtime();
    ShortestPathDijekstra(h, LCOUNT, 1, l_matrix, l_D, l_prev);
    double lend = wtime() - start;
    printf("Dijekstra algorythm output:\n\n");
    printf("i:\t\t");
    for ( int i = 1; i < LCOUNT + 1; i++ )
    {
        printf("%d\t", i);
    }
    printf("\n\nD[i]:\t\t");
    for ( int i = 1; i < LCOUNT + 1; i++ )
    {
        printf("%d\t", l_D[i]);
    }
    printf("\n\nprev[i]:\t");
    for ( int i = 1; i < LCOUNT + 1; i++ )
    {
        printf("%d\t", l_prev[i]);
    }
    printf("\n\nTime of running: %.12f\n\n", lend);
    printf("===================================\n\n");
    create_shell_graph(s_matrix);
    heap_free(h);
    h = heap_create(SCOUNT);
    int s_D[SCOUNT+1];
    int s_prev[SCOUNT+1];
    start = wtime();
    ShortestPathDijekstra(h, SCOUNT, 1, s_matrix, s_D, s_prev);
    double send = wtime() - start;
    printf("Create shell graph 100*100 with edges weight = 5\n\n");
    printf("Dijekstra algorythm output for the first 10 and last 10 vertices:\n\n");
    printf("i:\t\t");
    for ( int i = 1; i < SCOUNT + 1; i++ )
    {
        printf("%d\t", i);
        if ( i == 10 )
            i = SCOUNT - 10;
    }
    printf("\n\nD[i]:\t\t");
    for ( int i = 1; i < SCOUNT + 1; i++ )
    {
        printf("%d\t", s_D[i]);
        if ( i == 10 )
            i = SCOUNT - 10;
    }
    printf("\n\nprev[i]:\t");
    for ( int i = 1; i < SCOUNT + 1; i++ )
    {
        printf("%d\t", s_prev[i]);
        if ( i == 10 )
            i = SCOUNT - 10;
    }
    printf("\n\nTime of running: %.12f\n\n", send);
    return 0;
}