#include <stdio.h>

void generateFactors(int n, int divisor) {
    if (divisor > n / 2) {
        printf("%d ", n);  // Print n itself as a factor
        return;
    }

    if (n % divisor == 0) {
        printf("%d ", divisor);
        generateFactors(n / divisor, divisor);
    } else {
        generateFactors(n, divisor + 1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Factors of %d are: ", num);
    generateFactors(num, 2);  // Start with divisor = 2
    printf("\n");

    return 0;
}
