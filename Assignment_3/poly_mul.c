/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 3
Program     : Multiplication of First-Order Polynomials

Description :
Reads two first-order polynomials and computes
their product.

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
    printf("The product of %.2f*x + %.2f and %.2f*x + %.2f = %.2f*x^2 + %.2f*x + %.2f\n", 
           a1, b1, a2, b2, product_a, product_b, product_c);
    return 0;
}