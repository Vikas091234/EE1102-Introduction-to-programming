/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 2
Program     : Maximum Value of an Integer

Description :
Explores the maximum value that can be represented
by an integer using an iterative approach.

Note:
This implementation relies on integer overflow and is
kept as part of the original coursework. A standards-
compliant implementation would use INT_MAX from
<limits.h>.

Concepts:
- Integer Representation
- Integer Overflow
- Data Types

Author      : Vikas Raj
---------------------------------------------------------
*/
#include <stdio.h>

int main() {
    int maxInt = 1;

    // Increment maxInt until it overflows, which will result in the maximum positive value
    while (maxInt + 1 > maxInt) {
        maxInt = maxInt + 1;
    }

    // Print the calculated maximum value for an int
    printf("Maximum value for an int: %d\n", maxInt);

    return 0;
}
