/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 7
Program     : First-Order Polynomial Generator

Description :
Generates a first-order polynomial of the form
(x + a) and stores it using an array of coefficients.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

// Function to create a first-order polynomial (x + a)
// stored inside a fixed-size integer array of length 10.
//
// NOTE: This representation stores coefficients in reverse order:
// - array[9] holds the constant term (a)
// - array[8] holds the coefficient of x¹
// - array[0]..array[7] remain zero (higher powers not used)
void ROLLNO_poly1order(int a, int array[]) {

    // Initialize all 10 array elements to 0.
    // This ensures the polynomial starts as 0 + 0x + 0x² + ...
    for (int i = 0; i < 10; ++i) {
        array[i] = 0;
    }

    // Store the polynomial (x + a) using this specific indexing scheme:
    // array[8] → coefficient of x¹
    // array[9] → constant term
    array[8] = 1;  // coefficient of x
    array[9] = a;  // constant term
}

int main() {
    int a;
    int array[10];

    // Ask the user to enter the constant 'a'
    printf("Enter a number 'a': ");
    scanf("%d", &a);

    // Fill the array with the polynomial (x + a)
    // using the ROLLNO_poly1order function
    ROLLNO_poly1order(a, array);

    // Display the value of 'a' that was read
    printf("\nNumber read: %d\n", a);

    // Print the complete array to show how the polynomial
    // (x + a) is stored in this reversed coefficient format
    printf("Modified array: [");
    for (int i = 0; i < 9; ++i) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[9]);

    return 0;
}
