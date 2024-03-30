#include <stdio.h>

struct Item {
    int value;
    int weight;
};

void knapsackGreedy(int W, struct Item items[], int n) {
   
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio1 = (double)items[i].value / items[i].weight;
            double ratio2 = (double)items[j].value / items[j].weight;
            if (ratio1 < ratio2) {
               
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int totalValue = 0;
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
            printf("Added item with value %d and weight %d\n", items[i].value, items[i].weight);
        }
    }

    printf("Total value of items in knapsack: %d\n", totalValue);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    knapsackGreedy(W, items, n);

    return 0;
}

//output:-
//Enter the number of items: 3
//Enter the value and weight of each item:
//Item 1: 5
//6
//Item 2: 7
//5
//Item 3: 3
//7
//Enter the capacity of the knapsack: 7
//Added item with value 7 and weight 5
//Total value of items in knapsack: 7

//--------------------------------
//Process exited after 29.49 seconds with return value 0
//Press any key to continue . . .