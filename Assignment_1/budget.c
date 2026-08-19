/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 2
Program     : Institute Budget Estimation

Description :
Calculates the total institute budget in rupees and
estimates the maximum number of computers that can
be purchased using the allocated budget.

Concepts:
- long long int
- Integer Arithmetic
- Data Type Selection
- Formatted Output

Author      : Vikas Raj
---------------------------------------------------------
*/
#include <stdio.h>

int main() { 
    
    long long int budgetInCrores = 600; // Budget in crores
    long long int croreToRupees = 10000000; // Conversion factor: 1 crore = 10 million Rupees
    int computerCost = 40000; // Cost of one lab computer in Rupees

    // Calculate the total budget in Rupees
    long long int budgetInRupees = budgetInCrores * croreToRupees;

    // Calculate the number of computers that can be bought
    long long int numComputers = budgetInRupees / computerCost;

    // Print the budget and the number of computers that can be bought
    printf("The budget is Rs. %lld. We can buy %lld computers.\n", budgetInRupees, numComputers);

    return 0;
}