/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 3
Program     : Quadratic Equation Solver

Description :
Reads the coefficients of a quadratic equation,
determines the nature of its roots using the
discriminant, and computes the roots.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, discriminant, root1, root2;

    printf("Enter coefficients (a, b, c) of the function (p = a*x^2 + b*x + c):\n");
    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f", &c);

    // --- HANDLE a = 0 FIRST ---
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Every real number is a solution (0 = 0).\n");
            } else {
                printf("Invalid equation: No solution exists (%.2f = 0).\n", c);
            }
        } else {
            float linearRoot = -c / b;
            printf("Since a = 0, this is a linear equation (bx + c = 0).\n");
            printf("The single root is %f.\n", linearRoot);
        }
    } 
    // --- QUADRATIC LOGIC (when a != 0) ---
    else {
        discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            // Real and different roots
            root1 = (-b + sqrtf(discriminant)) / (2 * a);
            root2 = (-b - sqrtf(discriminant)) / (2 * a);
            printf("D is %f. Hence the roots are real and different.\n", discriminant);
            printf("The two roots are %f and %f respectively.\n", root1, root2);
        } else if (discriminant == 0) {
            // Real and same roots
            root1 = -b / (2 * a);
            printf("D is %f. Hence the roots are real and same.\n", discriminant);
            printf("The two roots are %f and %f respectively.\n", root1, root1);
        } else {
            // Complex roots
            float realPart = -b / (2 * a);
            float imaginaryPart = sqrtf(-discriminant) / (2 * a);
            printf("D is %f. Hence the roots are complex and different.\n", discriminant);
            printf("The two roots are %.2f + %.2fi and %.2f - %.2fi respectively.\n", 
                   realPart, imaginaryPart, realPart, imaginaryPart);
        }
    }

    return 0;
}
