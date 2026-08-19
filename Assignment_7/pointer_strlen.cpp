/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 8
Program     : Custom String Length

Description :
Computes the length of a string using pointer
arithmetic without using the standard strlen()
function.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

// -------------------------------------------------------------
// Function: strlen1
// Purpose : Calculate the length of a string using pointer arithmetic.
// Arguments:
//    s -> pointer to the first character of the string
//
// How it works:
//    - A second pointer 'p' stores the starting address.
//    - The pointer 's' is moved forward until it reaches '\0'.
//    - The difference (s - p) gives the number of characters.
// -------------------------------------------------------------
int my_strlen(char *s) {
    char *p = s;  // Save the starting position of the string

    // Move pointer 's' until the null terminator is reached
    while (*s != '\0') {
        s++;      // Advance to the next character
    }

    // Length = distance between end pointer and start pointer
    return s - p;
}

int main() {
    char inputString[100];  // Buffer to store the user's string

    // Prompt user for input
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // ---------------------------------------------------------
    // Remove the newline character added by fgets().
    // Without this step, strlen1() would count the '\n' too.
    // ---------------------------------------------------------
    for (int i = 0; i < sizeof(inputString); i++) {
        if (inputString[i] == '\n') {
            inputString[i] = '\0';  // Replace newline with string terminator
            break;
        }
    }

    // Display the length obtained from our custom strlen1()
    printf("Length of the string: %d\n", my_strlen(inputString));

    return 0;
}
