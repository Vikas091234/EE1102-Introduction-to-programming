/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 4
Program     : Taylor Series Approximation of ln(1+x)

Description :
Approximates the natural logarithm ln(1+x) using
the first ten terms of its Taylor series expansion
for values of x in the interval (-1, 1).

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {
    double x, term, result = 0;

    printf("Enter the value of x (-1 < x < 1): ");
    scanf("%lf", &x);

    if (x <= -1 || x >= 1) {
        printf("Error: x must be between -1 and 1.\n");
        return 1;
    }

    double xn = x;   

    for (int n = 1; n <= 10; ++n) {
        term = xn / n;
        if (n % 2 == 0) term = -term;

        result += term;
        xn *= x;     
    }

    printf("ln(1+%lf) ≈ %lf\n", x, result);
    return 0;
}
