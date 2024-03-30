#include <stdio.h>

int reverse(int num) {
    static int rev = 0;
    if (num == 0) {
        return rev;
    }
    rev = rev * 10 + num % 10;
    return reverse(num / 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int reversed_num = reverse(num);
    printf("Reverse of %d is %d\n", num, reversed_num);
    return 0;
}

//output:-
//Enter a number: 4567
//Reverse of 4567 is 7654

//--------------------------------
//Process exited after 9.398 seconds with return value 0
//Press any key to continue . . .