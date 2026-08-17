/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 1
Program     : Sum of Five Integers

Description :
Reads five integers from the user and computes
their sum.

Concepts:
- Variables
- scanf()
- printf()
- Arithmetic operators

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {
    // Declare variables of type int
    int num1, num2, num3, num4, num5, sum;

    // Take input from the user
    printf("Enter five integers separated by spaces: ");
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);

    // Calculate the sum
    sum = num1 + num2 + num3 + num4 + num5;

    // Print the sum in the specified format
    printf("The sum of %d, %d, %d, %d, and %d is: %d\n", num1, num2, num3, num4, num5, sum);

    return 0;
}