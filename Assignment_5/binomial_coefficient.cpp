/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 5
Program     : Binomial Coefficient Calculator

Description :
Computes the binomial coefficient (N choose K)
using recursive factorial functions.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the binomial coefficient
unsigned long long binomialCoefficient(int N, int K) {
    // Ensure K is not greater than N
    if (K > N) {
        return 0; // Invalid input
    }

    // Optimize using symmetry property: C(N, K) == C(N, N - K)
    if (K > N - K) {
        K = N - K;
    }

    // Use the formula (N choose K) = N! / (K! * (N-K)!)
    return factorial(N) / (factorial(K) * factorial(N - K));
}

int main() {
    int N, K;

    // enter the values
    printf("Enter two positive integers N and K (N choose K): ");
    scanf("%d %d", &N, &K);

    // Check if the input is valid
    if (N < 0 || K < 0) {
        printf("Please enter non-negative integers.\n");
        return 1;
    }

    // Calculate and print the binomial coefficient
    printf("Binomial coefficient (%d choose %d) is %llu\n", N, K, binomialCoefficient(N, K));

    return 0;
}