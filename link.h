#define LCOUNT 20

typedef struct edge
{
    int src;
    int dest;
    int value;
} edge;


void create_link_graph(int matrix[LCOUNT][LCOUNT], edge **edges, int *edges_count);

