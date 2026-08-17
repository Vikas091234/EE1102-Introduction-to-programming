/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 1
Program     : Print Student Details

Description :
Prints the student's roll number and name.

Concepts:
- Character arrays
- Formatted output

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {
    // Declare and initialize variables
    char rollNumber[] = "EE19B108";
    char name[] = "vikas raj";

    // Print roll number and name
    printf("%s\n%s\n", rollNumber, name);

    return 0;
}