#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int list[MAX_SIZE];
    int size, number, i;

    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter %d sorted numbers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &number);

    for (i = 0; i < size; i++) {
        if (number < list[i]) {
           
            for (int j = size; j > i; j--) {
                list[j] = list[j - 1];
            }
        
            list[i] = number;
            size++;
            break;
        }
    }
    printf("Updated list: ");
    for (i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
