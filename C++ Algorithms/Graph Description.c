/************************************************************************
This program analyzes many features of a graph input as a 2d adjacency matrix.

It analyzes the following:

 1. Type - trivial or nontrivial        2. Order - number of vertices
 3. Size - number of edges              4. Minimum and Maximum degrees
 5. Regular - yes (give size) or no     6. Complete - yes or no
 7. Empty - does graph have 0 edges     8. Bipartite - no odd cycle, yes or no
 9. Connected graph - yes or no        10. Number of components
11. Is graph a tree?                   12. Minimum Spanning Tree (if tree)
13. Dijkstra (if tree, for all nodes)

*************************************************************************/

/*************************Libraries and Constants************************/
#include <stdio.h>

struct NodeName
{
    char name[100];
};

/**************************Function Prototypes***************************/
int graphSize( int directed, float **theGraph );


/**********************************Main**********************************/
int main()
{
    printf("This program analyzes many features of a graph input as a 2d adjacency matrix.\n");
    printf("The graph can be directed or undirected. The features are as follows:\n");
    printf(" 1. Type - trivial or nontrivial        2. Order - number of vertices\n");
    printf(" 3. Size - number of edges              4. Minimum and Maximum degrees\n");
    printf(" 5. Regular - yes (give size) or no     6. Complete - yes or no\n");
    printf(" 7. Empty - does graph have 0 edges     8. Bipartite - no odd cycle, yes or no\n");
    printf(" 9. Connected graph - yes or no        10. Number of components\n");
    printf("11. Is graph a tree?                   12. Minimum Spanning Tree (if tree)\n");
    printf("13. Dijkstra (if tree, for all nodes)\n\n");

    int order, r, c, directed;

    //get directed or undirected
    do
    {
        printf("Enter 1 if the graph is undirected.\n");
        printf("Enter 2 if the graph is directed.\n");
        scanf("%d", &directed );
        printf("\n");
    }while( directed < 1 || directed > 2);

    //get number of nodes
    do
    {
        printf("Enter the number of nodes (2 or greater): ");
        scanf("%d", &order);
        printf("\n");
    }while( order < 2 );

    struct NodeName myNames[order];
    float graph[order][order];

    //enter names for nodes
    printf("Enter the names of the node(s):\n");
    for( r = 0; r < order; r++ )
    {
        printf("Node %d: ", r );
        scanf("%s", &myNames[r]);
    }//for

    //enter value for edges
    printf("\nEnter the values for the edges. Undirected edges only need to be entered once.\n");
    printf("Enter -1 if there is no edge from the first node to the second node.\n\n");
    if( directed == 1 )
    {
        for( r = 0; r < order; r++ )
            for( c = r; c < order; c++ )
            {
                printf("Enter the value for the edge from Node %s to Node %s: ", myNames[r].name, myNames[c].name );
                scanf("%f", &graph[r][c] );
            }//for
    }//if
    else
    {
        for( r = 0; r < order; r++ )
            for( c = 0; c < order; c++ )
            {
                printf("Enter the value for the edge from Node %s to Node %s: ", myNames[r].name, myNames[c].name );
                scanf("%f", &graph[r][c] );
            }//for
    }//else

}//main

int graphSize( int directed, float **theGraph )
{
    printf("Value at 1: %f", theGraph[0][0]);

}//graphSize
