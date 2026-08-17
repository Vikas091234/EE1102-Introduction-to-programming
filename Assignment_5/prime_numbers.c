/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 5
Program     : Prime Number Checker

Description :
Determines whether a given integer is prime by
testing divisibility.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {
    int n, i = 2;
    
    // enter the number
    printf("Enter a number (n >= 2): ");
    scanf("%d", &n);

    // Check if n is less than 2
    while (n < 2) {
        printf("Please enter a number greater than or equal to 2: ");
        scanf("%d", &n);
    }

    // Check if n is a prime number
    while ( i*i <= n ) {
        if (n % i == 0) {
            printf("%d is not a prime number.\n", n);
            return 0;
        }
        i++;
    }

    printf("%d is a prime number.\n", n);

    return 0;
}