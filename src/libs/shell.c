#include <stdio.h>

#include "shell.h"
#include "graphs.h"

void generate_shell(int **matrix)
{
    for ( int i = 0; i < SCOUNT / SN; i++ )
        {
            for (int j = 1; j < SN + 1; j++)
            {
                if ( j < SN ) {
                    matrix[i * SN + j - 1][i * SN + j + 1 - 1] = matrix[i * SN + j + 1 - 1][i * SN + j - 1] = 5;
                }
                if ( i < SCOUNT / SN - 1 ) {
                    matrix[i * SN + j - 1][( i + 1 ) * SN + j - 1] = matrix[( i + 1 ) * SN + j - 1][i * SN + j - 1] = 5;
                }
            }
        }
}

void create_shell_graph(int **matrix)
{
    for ( int i = 0; i < SCOUNT; i++ )
    {
        for ( int j = 0; j < SCOUNT; j++ )
        {
            matrix[i][j] = 0;
        }
    }
    generate_shell(matrix);

}