/*
Course      : EE1103 - Numerical Methods
Assignment  : 9
Program     : Trapezoidal Numerical Integration

Description :
Computes the definite integral of a function using
the trapezoidal rule. The function to be integrated
is passed to trapzd() using a function pointer.

Author      : Vikas Raj
*/

#include <stdio.h>

// ---------------------------------------------------------------
// Function: func
// Purpose : This is the integrand: f(x) = 1 / (1 + x^2)
// ---------------------------------------------------------------
float func(float x) {
    return 1.0f / (1.0f + x * x);
}

// ---------------------------------------------------------------------------
// Function: trapzd
// Purpose : Perform numerical integration using the standard Trapezoidal Rule.
//           It divides the interval [a, b] into exactly n equal subintervals.
//
// Arguments:
//    func : pointer to the function f(x) to integrate
//    a, b : lower and upper integration limits
//    n    : total number of subintervals (trapezoids)
// ---------------------------------------------------------------------------
float trapzd(float (*func)(float x), float a, float b, int n) {
    // Input validation
    if (n <= 0) {
        return 0.0f;
    }

    // Step size (width of each trapezoid)
    float h = (b - a) / n;
    float sum = 0.0f;

    // Sum up the area of each trapezoid: (0.5 * f(x1) + 0.5 * f(x2)) * h
    for (int i = 0; i < n; ++i) {
        float x1 = a + i * h;
        float x2 = a + (i + 1) * h;

        sum += (0.5f * func(x1) + 0.5f * func(x2)) * h;
    }

    return sum;
}

int main() {
    float a, b, result;
    int n;

    // Ask user for integration limits
    printf("Enter the limits a and b: ");
    scanf("%f %f", &a, &b);

    // Ask for number of intervals n
    printf("Enter the number of intervals n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Number of intervals must be greater than 0.\n");
        return 1;
    }

    // Call the trapezoidal routine with function pointer
    result = trapzd(func, a, b, n);

    // Output the computed integral
    printf("Definite integral: %.6f\n", result);

    return 0;
}