/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 7
Program     : Polynomial Multiplication

Description :
Multiplies two polynomials represented using
coefficient arrays and displays the resulting
polynomial.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

#define SIZE 10          // array size (supports degrees 0..9)
#define MAX_DEG (SIZE-1)

typedef long long ll;

void init_poly(ll p[]) {
    for (int i = 0; i < SIZE; ++i) p[i] = 0;
}

int read_poly(ll p[]) {
    init_poly(p);
    for (int i = 0; i < SIZE; ++i) {
        printf("Enter coefficient for x^%d: ", i);
        if (scanf("%lld", &p[i]) != 1) return 1;
    }
    return 0;
}

int degree(const ll p[]) {
    for (int i = MAX_DEG; i >= 0; --i) {
        if (p[i] != 0) return i;
    }
    return 0; // zero polynomial has degree 0 by convention here
}

// Multiply poly1 and poly2 into result.
// Return 0 on success; 1 if product doesn't fit (degree overflow) or invalid.
int ROLLNO_poly_mult(const ll poly1[], const ll poly2[], ll result[]) {
    int d1 = degree(poly1);
    int d2 = degree(poly2);

    if (d1 + d2 > MAX_DEG) {
        return 1; // won't fit
    }

    init_poly(result);

    for (int i = 0; i <= d1; ++i) {
        if (poly1[i] == 0) continue;
        for (int j = 0; j <= d2; ++j) {
            if (poly2[j] == 0) continue;
            result[i + j] += poly1[i] * poly2[j];
        }
    }
    return 0;
}

void print_poly(const ll p[]) {
    int first = 1;
    for (int i = MAX_DEG; i >= 0; --i) {
        if (p[i] == 0) continue;
        ll coeff = p[i];

        if (!first) {
            if (coeff > 0) printf(" + ");
            else { printf(" - "); coeff = -coeff; }
        } else {
            if (coeff < 0) { printf("-"); coeff = -coeff; }
        }

        if (i == 0) {
            printf("%lld", coeff);
        } else if (i == 1) {
            if (coeff == 1) printf("x");
            else printf("%lldx", coeff);
        } else {
            if (coeff == 1) printf("x^%d", i);
            else printf("%lldx^%d", coeff, i);
        }
        first = 0;
    }
    if (first) printf("0"); // zero polynomial
    printf("\n");
}

int main() {
    ll poly1[SIZE], poly2[SIZE], result[SIZE];

    printf("Enter coefficients for the first polynomial:\n");
    if (read_poly(poly1)) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\nEnter coefficients for the second polynomial:\n");
    if (read_poly(poly2)) {
        printf("Invalid input.\n");
        return 1;
    }

    if (ROLLNO_poly_mult(poly1, poly2, result) != 0) {
        printf("\nError: The product cannot fit into degree %d (overflow of degree).\n", MAX_DEG);
        return 1;
    }

    printf("\nPolynomial product:\n");
    print_poly(result);

    return 0;
}
