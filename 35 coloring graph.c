#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10 
void printSolution(int color[], int V);
bool isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int color[], int c, int V) 
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}
bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int m, int color[], int v, int V) 
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++) 
	{
        if (isSafe(v, graph, color, c, V)) 
		{
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1, V))
                return true;
            color[v] = 0;
        }
    }
    return false;
}
bool graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int m, int V) 
{
    int color[MAX_VERTICES];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    if (!graphColoringUtil(graph, m, color, 0, V)) 
	{
        printf("Solution does not exist\n");
        return false;
    }
    printf("Solution exists: Following are the assigned colors:\n");
    printSolution(color, V);
    return true;
}
void printSolution(int color[], int V) 
{
    for (int i = 0; i < V; i++)
        printf("Vertex %d --> Color %d\n", i, color[i]);
}
int main() 
{
    int V, m;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the number of colors available: ");
    scanf("%d", &m);
    graphColoring(graph, m, V);
    return 0;
}
