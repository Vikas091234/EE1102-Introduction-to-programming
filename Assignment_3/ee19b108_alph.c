/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 4
Program     : Lowercase Alphabet Printer

Description :
Prints the lowercase English alphabet from 'a' to 'z'
using a for loop, with each letter separated by commas.

Author      : Vikas Raj
---------------------------------------------------------
*/
#include <stdio.h>

int main() {
    printf("RollNumber-alph.c: Printing lowercase alphabet separated by commas:\n");

    // Loop to print lowercase letters separated by commas
    for (int i = 'a'; i <= 'z'; ++i) {
        printf("%c", i);
        
        // Print a comma after each letter except the last one
        if (i < 'z') {
            printf(", ");
        }
    }

    printf("\n");

    return 0;
}