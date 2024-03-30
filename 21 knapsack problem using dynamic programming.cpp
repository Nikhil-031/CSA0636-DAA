#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter the values and weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum value that can be obtained: %d\n", knapsack(W, wt, val, n));

    return 0;
}

//output:-
//Enter the number of items: 2
//Enter the values and weights of items:
//1 3
//2 4
//Enter the capacity of the knapsack: 6
//Maximum value that can be obtained: 2

//--------------------------------
//Process exited after 12.66 seconds with return value 0
//Press any key to continue . . .