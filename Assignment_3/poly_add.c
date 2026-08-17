/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 3
Program     : Addition of First-Order Polynomials

Description :
Reads two first-order polynomials and computes
their sum.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {
    // Coefficients for P1(x) = a1*x + b1 and P2(x) = a2*x + b2
    float a1, b1, a2, b2;
    float sum_a, sum_b;

    // Read coefficients for the first polynomial
    printf("Enter coefficients for the first polynomial (a1*x + b1):\n");
    printf("a1: ");
    scanf("%f", &a1);
    printf("b1: ");
    scanf("%f", &b1);

    // Read coefficients for the second polynomial
    printf("\nEnter coefficients for the second polynomial (a2*x + b2):\n");
    printf("a2: ");
    scanf("%f", &a2);
    printf("b2: ");
    scanf("%f", &b2);

    // Compute polynomial addition: (a1 + a2)x + (b1 + b2)
    sum_a = a1 + a2;
    sum_b = b1 + b2;

    // Output the resulting polynomial
    printf("\n--- Polynomial Addition Result ---\n");
    printf("P1(x) = %.2fx + %.2f\n", a1, b1);
    printf("P2(x) = %.2fx + %.2f\n", a2, b2);
    
    // Display the sum clearly
    if (sum_b >= 0) {
        printf("Sum   = %.2fx + %.2f\n", sum_a, sum_b);
    } else {
        printf("Sum   = %.2fx - %.2f\n", sum_a, -sum_b); // Handles negative constant term cleanly
    }

    return 0;
}