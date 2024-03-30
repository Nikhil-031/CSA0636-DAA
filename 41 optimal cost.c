#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int findOptimalCost(int costs[], int n) {
    int minCost = costs[0];

    for (int i = 1; i < n; i++) {
        minCost = min(minCost, costs[i]);
    }

    return minCost;
}

int main() {
    int n;  
    printf("Enter the number of costs: ");
    scanf("%d", &n);

    int costs[n]; 
   
    printf("Enter the costs:\n");
    for (int i = 0; i < n; i++) {
        printf("Cost %d: ", i + 1);
        scanf("%d", &costs[i]);
    }

    int optimalCost = findOptimalCost(costs, n);

    printf("The optimal cost is: %d\n", optimalCost);

    return 0;
}
