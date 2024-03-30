#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
int vertices, startVertex;
void initializeGraph() 
{
    for (int i = 0; i < MAX_VERTICES; i++) 
	{
        for (int j = 0; j < MAX_VERTICES; j++) 
		{
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) 
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

bool isSafe(int v, int pos) 
{
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) 
	{
        if (path[i] == v)
            return false;
    }

    return true;
}

bool hamiltonianUtil(int pos) 
{
    if (pos == vertices) 
	{
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 1; v < vertices; v++) 
	{
        if (isSafe(v, pos)) 
		{
            path[pos] = v;
            if (hamiltonianUtil(pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void hamiltonian() 
{
    for (int i = 0; i < vertices; i++)
        path[i] = -1;
    path[0] = startVertex;
    if (hamiltonianUtil(1)) 
	{
        printf("Hamiltonian Circuit exists: ");
        for (int i = 0; i < vertices; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]);
    } 
	else 
	{
        printf("Hamiltonian Circuit does not exist\n");
    }
}
int main() 
{
    initializeGraph();
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the start vertex (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);
    printf("Enter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);
    printf("Enter the edges (format: u v): \n");
    for (int i = 0; i < numEdges; i++) 
	{
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    hamiltonian();
    return 0;
}
