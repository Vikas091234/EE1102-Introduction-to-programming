/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 7
Program     : Polynomial Exponentiation

Description :
Computes (x + a)^n using repeated polynomial
multiplication and displays the expanded polynomial.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

#define MAX_DEG 9        // maximum degree we can store (0..9)
#define SIZE (MAX_DEG + 1)

void poly_set_zero(int p[]) {
    for (int i = 0; i < SIZE; ++i) p[i] = 0;
}

// create polynomial (x + a): coeff[1] = 1, coeff[0] = a
void ROLLNO_poly1order(int a, int poly[]) {
    poly_set_zero(poly);
    poly[1] = 1;
    poly[0] = a;
}

// multiply poly1 and poly2 into result; return 0 on success, 1 if degree overflow occurs
int ROLLNO_poly_mult(const int poly1[], const int poly2[], int result[]) {
    poly_set_zero(result);

    for (int i = 0; i <= MAX_DEG; ++i) {
        if (poly1[i] == 0) continue;
        for (int j = 0; j <= MAX_DEG; ++j) {
            if (poly2[j] == 0) continue;
            int deg = i + j;
            if (deg > MAX_DEG) {
                return 1; // product doesn't fit
            }
            result[deg] += poly1[i] * poly2[j];
        }
    }
    return 0;
}

// compute (x + a)^n into result; return 0 on success, 1 on overflow / invalid n
int ROLLNO_poly_pow(int a, int n, int result[]) {
    if (n < 0) return 1; // invalid exponent for this routine

    int base[SIZE];
    ROLLNO_poly1order(a, base);

    // start result as 1 (x^0)
    poly_set_zero(result);
    result[0] = 1;

    // repeated multiplication by base (simple approach)
    for (int k = 0; k < n; ++k) {
        int temp[SIZE];
        if (ROLLNO_poly_mult(result, base, temp) != 0) {
            return 1; 
        }
        // copy temp -> result
        for (int i = 0; i < SIZE; ++i) result[i] = temp[i];
    }
    return 0;
}

void print_poly(const int poly[]) {
    int first = 1;
    for (int deg = MAX_DEG; deg >= 0; --deg) {
        int c = poly[deg];
        if (c == 0) continue;
        if (!first) {
            if (c > 0) printf(" + ");
            else printf(" - ");
        } else {
            if (c < 0) printf("-");
        }
        int mag = (c < 0) ? -c : c;
        if (deg == 0) {
            printf("%d", mag);
        } else if (deg == 1) {
            if (mag == 1) printf("x");
            else printf("%dx", mag);
        } else {
            if (mag == 1) printf("x^%d", deg);
            else printf("%dx^%d", mag, deg);
        }
        first = 0;
    }
    if (first) printf("0"); // zero polynomial
    printf("\n");
}

int main() {
    int a, n;
    int result[SIZE];

    printf("Enter a number 'a': ");
    if (scanf("%d", &a) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter a non-negative exponent 'n': ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int status = ROLLNO_poly_pow(a, n, result);

    if (status == 0) {
        printf("\nPolynomial (x+%d)^%d:\n", a, n);
        print_poly(result);
    } else {
        printf("\nError: The polynomial does not fit within degree %d or invalid input.\n", MAX_DEG);
    }

    return 0;
}
