#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int optimalBST(int *keys, int *freq, int n) {
    int cost[n][n];

    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
    
            for (int k = i; k <= j; k++) {
                int rootCost = ((k > i) ? cost[i][k - 1] : 0) +
                               ((k < j) ? cost[k + 1][j] : 0) +
                               freq[k];
                if (rootCost < cost[i][j]) {
                    cost[i][j] = rootCost;
                }
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int *keys = (int *)malloc(n * sizeof(int));
    int *freq = (int *)malloc(n * sizeof(int));

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the corresponding frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int minCost = optimalBST(keys, freq, n);
    printf("The minimum cost of the optimal binary search tree is: %d\n", minCost);

    free(keys);
    free(freq);

    return 0;
}