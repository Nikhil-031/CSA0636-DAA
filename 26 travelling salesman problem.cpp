#include <stdio.h>
#include <stdlib.h>

#define V 4

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[][V], int mask, int pos, int dp[][V]) {
    if (mask == (1 << V) - 1)
        return graph[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    for (int city = 0; city < V; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    int graph[V][V];
    int dp[1 << V][V];
    
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = tsp(graph, 1, 0, dp);

    printf("Minimum cost of the Travelling Salesman Problem: %d\n", ans);

    return 0;
}

//output:-
//Enter the adjacency matrix for the graph:
//3 4 5 6
//4 5 6 3
//7 8 4 7
//2 5 7 8
//Minimum cost of the Travelling Salesman Problem: 18

//--------------------------------
//Process exited after 19.63 seconds with return value 0
//Press any key to continue . . .