/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 8
Program     : Custom String Concatenation

Description :
Implements the functionality of strcat() using
pointer arithmetic without relying on the
standard string library.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

// ---------------------------------------------------------------
// Custom implementation of strcat() using pointer manipulation.
// NOTE: This function shadows the standard library strcat(), 
// which is allowed but NOT recommended in real projects.
// ---------------------------------------------------------------
void my_strcat(char *s, char *t) {

    // Move pointer 's' forward until it reaches the null terminator.
    // This positions 's' at the end of the first string.
    while (*s != '\0') {
        s++;
    }

    // Copy characters from 't' into the end of 's'
    // One character at a time, including the final '\0'.
    //
    // The expression (*s = *t) assigns the character,
    // and the loop continues until the assigned value is '\0'.
    while ((*s = *t) != '\0') {
        s++;    // Advance pointer in destination string
        t++;    // Advance pointer in source string
    }
}

int main() {
    char firstString[100];   // Buffer for first string (max length 99 chars)
    char secondString[100];  // Buffer for second string

    // Read the first string from the user.
    // scanf("%s") stops at whitespace.
    printf("Enter the first string: ");
    scanf("%99s", firstString);

    // Read the second string.
    printf("Enter the second string: ");
    scanf("%99s", secondString);

    // Concatenate secondString to firstString using our custom strcat().
    // No bounds checking is done — if combined length > 99 chars,
    // behavior becomes undefined.
    my_strcat(firstString, secondString);

    // Print the final concatenated string.
    printf("Concatenated string: %s\n", firstString);

    return 0;
}
