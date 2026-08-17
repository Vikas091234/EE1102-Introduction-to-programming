/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 2
Program     : Ratio of Sum of Squares

Description :
Reads three floating-point numbers and computes the
ratio of the sum of their squares to their sum.

Concepts:
- Floating-Point Arithmetic
- User Input
- Mathematical Expressions
- Formatted Output

Author      : Vikas Raj
---------------------------------------------------------
*/
#include <stdio.h>

int main() {
    float A, B, C;

    // The user to enter the first number
    printf("Enter the first number: ");
    scanf("%f", &A);

    // The user to enter the second number
    printf("Enter the second number: ");
    scanf("%f", &B);

    // The user to enter the third number
    printf("Enter the third number: ");
    scanf("%f", &C);

    float sumSquares = A * A + B * B + C * C;
    float sum = A + B + C;
    float ratio = sumSquares / sum;

    // Print the numbers and the calculated ratio in this format
    printf("A = %.2f; B = %.2f; C = %.2f;\n", A, B, C);
    printf("(A^2 + B^2 + C^2) / (A + B + C) = %.2f\n", ratio);

    return 0;
}