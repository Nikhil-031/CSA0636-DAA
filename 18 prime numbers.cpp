#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int i) {
   
    if (n <= 2) {
        return (n == 2) ? true : false;
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    
    return isPrime(n, i + 1);
}

void printPrimes(int n, int current) {
   
    if (current > n) {
        return;
    }
    
    if (isPrime(current, 2)) {
        printf("%d ", current);
    }
    
    printPrimes(n, current + 1);
}

int main() {
    int limit;
    
    printf("Enter a limit to generate prime numbers: ");
    scanf("%d", &limit);
    
    printf("Prime numbers up to %d are: ", limit);
    printPrimes(limit, 2); 
    printf("\n");
    
    return 0;
}

//output:-
//Enter a limit to generate prime numbers: 7
//Prime numbers up to 7 are: 2 3 5 7

//--------------------------------
//Process exited after 5.831 seconds with return value 0
//Press any key to continue . . .
