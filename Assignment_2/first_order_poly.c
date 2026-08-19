/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 3
Program     : Multiplication of Two-Variable Polynomials

Description :
Reads two first-order polynomials in two variables
and computes their product.

Author      : Vikas Raj
---------------------------------------------------------
*/
#include <stdio.h>

int main() {
    // Declare variables to store coefficients
    float a1, b1, a2, b2;

    // enter the coefficients
    printf("Enter the coefficients of the first polynomial (a1 and b1): ");
    scanf("%f %f", &a1, &b1);

    printf("Enter the coefficients of the second polynomial (a2 and b2): ");
    scanf("%f %f", &a2, &b2);

    // Calculate product
    float product_a = a1 * a2;
    float product_b = a1 * b2 + b1 * a2;
    float product_c = b1 * b2;

    // Display the product
    printf("The product of %.2f*x + %.2f*y and %.2f*x + %.2f*y = %.2f*x^2 + %.2f*xy + %.2f*y^2\n", a1, b1, a2, b2, product_a, product_b, product_c);

    return 0;
}