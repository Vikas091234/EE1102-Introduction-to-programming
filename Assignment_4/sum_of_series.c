/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 5
Program     : Alternating Series Calculator

Description :
Computes the sum of an alternating mathematical
series for different values of N and displays the
results in tabular form.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

// Function to calculate the sum of the series
double calculateSeriesSum(int n) {
    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            sum += (double)(i - 1) / i; // Odd term
        } else {
            sum -= (double)(i - 1) / i; // Even term
        }
    }

    return sum;
}

int main() {
    int N;

    // enter the values
    printf("Enter a positive integer N: ");
    scanf("%d", &N);

    // Check if the input is valid
    if (N <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Print the header for the table
    printf("\n%-8s%-14s%-14s\n", "N", "Even sum", "Odd sum");

    // Calculate and print the sum for each even and odd value of N
    for (int i = 2; i <= N; i += 2) {
        printf("%-8d%-14.4f%-14.4f\n", i, calculateSeriesSum(i), calculateSeriesSum(i + 1));
    }

    return 0;
}