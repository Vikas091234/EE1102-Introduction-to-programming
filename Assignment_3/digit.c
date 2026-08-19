/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 4
Program     : Decimal Digit Expansion

Description :
Reads an integer and prints its decimal expansion
by extracting each digit from least significant to
most significant.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {
    // Declare variables
    int number, originalNumber, digit;
    int power = 0;
    
    // Enter the input
    printf("Enter an integer: ");
    scanf("%d", &number);
    
    // Store the original number
    originalNumber = number;

    printf("%d = ", originalNumber);

    // Edge case for 0
    if (number == 0) {
        printf("0 * 10^0\n");
        return 0;
    }

    // Handle negative numbers if entered
    if (number < 0) {
        number = -number;
    }

    // Repeatedly extract the least significant digit and print with power of 10
    while (number > 0) {
        digit = number % 10;  // Extract least significant digit
        
        printf("%d * 10^%d", digit, power);
        
        number /= 10;         // Remove the last digit
        power++;              // Increment the power of 10

        // Print '+' only if there are remaining digits
        if (number > 0) {
            printf(" + ");
        }
    }

    printf("\n");

    return 0;
}