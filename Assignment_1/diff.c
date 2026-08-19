/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 2
Program     : Difference of Two Integers

Description :
Reads two integers from the user and computes their
difference in the format:

A - B = Difference

Concepts:
- Variables
- User Input
- Arithmetic Operators
- Formatted Output

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>

int main() {

    //the program is about calculating difference between two integer
    int num1, num2;
    
    // The user to enter the first integer
    printf("Enter the first integer: ");
    scanf("%d", &num1);
    
    // The user to enter the second integer
    printf("Enter the second integer: ");
    scanf("%d", &num2);
    
    int difference = num1 - num2;
    
    // The difference in the specified format
    printf("%d - %d = %d\n", num1, num2, difference);
    
    return 0;
}