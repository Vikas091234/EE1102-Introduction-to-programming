/*
Course      : EE1103 - Numerical Methods
Assignment  : 9
Program     : Pointer Array

Description :
Reads up to 10 strings and stores them using an
array of pointers with dynamically allocated memory.
The stored strings are then printed and the allocated
memory is freed.

Author      : Vikas Raj
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 10   // Maximum number of strings to read
#define MAX_LENGTH 30    // Maximum length of each input string

int main() {
    char *arr[MAX_STRINGS];   // Array of pointers to hold dynamically allocated strings
    char input[MAX_LENGTH];   // Temporary buffer to read each string

    printf("Enter up to %d strings (each up to %d characters):\n",
           MAX_STRINGS, MAX_LENGTH);

    // ------------------------------------------------------------------
    // INPUT LOOP: Read each string, remove newline, allocate memory,
    // and store it into arr[i].
    // ------------------------------------------------------------------
    for (int i = 0; i < MAX_STRINGS; ++i) {

        printf("Enter string %d: ", i + 1);

        // Read input using fgets() — safer than scanf("%s")
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Calculate string length once
        size_t len = strlen(input);

        // Remove the newline character added by fgets(), if present
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
            len--;  // Update length after removing newline
        }

        // Allocate memory for the string (+1 for '\0')
        arr[i] = (char *)malloc(len + 1);

        // Check if malloc succeeded
        if (arr[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation failed for string %d.\n", i + 1);
            
            // Clean up any previously allocated memory before exiting
            for (int j = 0; j < i; ++j) {
                free(arr[j]);
            }
            return 1;
        }

        // Copy the input string into the allocated memory block
        strcpy(arr[i], input);
    }

    printf("\nStrings entered:\n");

    // ------------------------------------------------------------------
    // OUTPUT LOOP: Print each stored string and free the memory.
    // ------------------------------------------------------------------
    for (int i = 0; i < MAX_STRINGS; ++i) {

        // Print the dynamically stored string
        printf("%s\n", arr[i]);

        // Free memory allocated for this string to avoid memory leaks
        free(arr[i]);
    }

    return 0;
}