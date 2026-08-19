/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 6
Program     : Polynomial Evaluation

Description :
Evaluates a polynomial for user-specified values of x
using the polynomial coefficients provided by the user.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

#define MAX_DEGREE 100  // Maximum polynomial degree supported

// Function to calculate the value of the polynomial for a given x using Horner's Method
double calculatePolynomial(int n, double coefficients[], double x) {
    double result = coefficients[n];

    // Evaluate from highest degree term down to constant term
    for (int i = n - 1; i >= 0; --i) {
        result = result * x + coefficients[i];
    }

    return result;
}

int main() {
    int n;

    // Get the order of the polynomial from the user
    printf("Enter the order of the polynomial (n): ");
    scanf("%d", &n);

    // Check if the order is valid within supported limits
    if (n < 0 || n > MAX_DEGREE) {
        printf("Invalid order. Please enter a value between 0 and %d.\n", MAX_DEGREE);
        return 1;
    }

    // Fixed-size array defined with compile-time constant size
    double coefficients[MAX_DEGREE + 1];

    // Get the coefficients from the user
    for (int i = 0; i <= n; ++i) {
        printf("Enter coefficient a%d: ", i);
        scanf("%lf", &coefficients[i]);
    }

    // Enter a loop to calculate f(x) for user-input values of x
    double x;
    do {
        // Get the value of x from the user
        printf("Enter a value of x (enter 0 to exit): ");
        scanf("%lf", &x);

        // Check if the user wants to exit
        if (x == 0) {
            printf("Exiting program.\n");
            break;
        }

        // Calculate and print f(x)
        double result = calculatePolynomial(n, coefficients, x);
        printf("f(%lf) = %lf\n", x, result);

    } while (1); // Infinite loop, breaks when user enters 0

    return 0;
}