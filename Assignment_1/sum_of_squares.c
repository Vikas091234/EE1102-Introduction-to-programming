/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 1
Program     : Sum of Squares

Description :
Reads three integers from the user and computes
the sum of their squares.

Concepts:
- Integer arithmetic
- Expressions
- User input
- Console output

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {
    // Declare variables of type int
    int num1, num2, num3, sumOfSquares;

    // Take input from the user
    printf("Enter three integers separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Calculate the sum of squares
    sumOfSquares = num1 * num1 + num2 * num2 + num3 * num3;

    // Print the result
    printf("The sum of squares is: %d\n", sumOfSquares);

    return 0;
}