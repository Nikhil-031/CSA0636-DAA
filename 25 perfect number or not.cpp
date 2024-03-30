#include <stdio.h>

int isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPerfect(n)) {
        printf("%d is a perfect number.\n", n);
    } else {
        printf("%d is not a perfect number.\n", n);
    }

    return 0;
}

//output:-
//Enter a number: 28
//28 is a perfect number.

//--------------------------------
//Process exited after 3.578 seconds with return value 0
//Press any key to continue . . .