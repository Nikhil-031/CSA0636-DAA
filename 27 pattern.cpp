#include <stdio.h>

int main() {
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
    	
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
//output-
//Enter the number of rows: 4
//1
//1 2
//1 2 3
//1 2 3 4

//--------------------------------
//Process exited after 2.651 seconds with return value 0
//Press any key to continue . . .