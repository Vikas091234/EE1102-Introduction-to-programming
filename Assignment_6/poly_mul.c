/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 6
Program     : Polynomial Multiplication

Description :
Reads two polynomials from the user, computes their
product, and displays the resulting polynomial.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

// Function to calculate the product of two second-order polynomials
void multiplyPolynomials(double a[], double b[], double result[]) {
    // For the product of two second-order polynomials, the result will be a fourth-order polynomial
    for (int k = 0; k <= 4; ++k) {
        result[k] = 0;

        // Calculate the product for the current k
        for (int i = 0; i <= 2; ++i) {
            int j = k - i;

            // Only add terms where both indices are valid
            if (j >= 0 && j <= 2) {
                result[k] += a[i] * b[j];
            }
        }
    }
}

int main() {
    // Declare arrays to store coefficients of two second-order polynomials and their product
    double p1[3], p2[3], product[5];

    // Get coefficients for the first polynomial (p1)
    printf("Enter coefficients for the first polynomial (p1) of order 2:\n");
    for (int i = 2; i >= 0; --i) {
        printf("Enter coefficient a%d: ", i);
        scanf("%lf", &p1[i]);
    }

    // Get coefficients for the second polynomial (p2)
    printf("\nEnter coefficients for the second polynomial (p2) of order 2:\n");
    for (int i = 2; i >= 0; --i) {
        printf("Enter coefficient b%d: ", i);
        scanf("%lf", &p2[i]);
    }

    // Print the two polynomials
    printf("\nPolynomial p1: %.2fx^2 + %.2fx + %.2f\n", p1[2], p1[1], p1[0]);
    printf("Polynomial p2: %.2fx^2 + %.2fx + %.2f\n", p2[2], p2[1], p2[0]);

    // Calculate and print the product of the two polynomials
    multiplyPolynomials(p1, p2, product);
    printf("\nProduct of p1 and p2: %.2fx^4 + %.2fx^3 + %.2fx^2 + %.2fx + %.2f\n",
           product[4], product[3], product[2], product[1], product[0]);

    return 0;
}