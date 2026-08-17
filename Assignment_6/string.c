/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 6
Program     : String Manipulation

Description :
Performs basic string operations using character
arrays and standard C programming techniques.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 15

int main() {
    int n;

    // Get the number of names from the user
    printf("Enter the number of names: ");
    scanf("%d", &n);

    // Check if the number of names is within valid limits
    if (n <= 0 || n > MAX_NAMES) {
        printf("Invalid number of names. Please enter a value between 1 and %d.\n", MAX_NAMES);
        return 1;
    }

    // Clear newline character left in the buffer by scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }

    // Fixed-size 2D array to store names (no malloc needed)
    char names[MAX_NAMES][MAX_LENGTH];

    // Read in names using fgets
    for (int i = 0; i < n; ++i) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], MAX_LENGTH, stdin);

        // Remove the newline character at the end
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Print the names separated by commas
    printf("Names entered: ");
    for (int i = 0; i < n; ++i) {
        printf("%s", names[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}