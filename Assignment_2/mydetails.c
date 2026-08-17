/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 2
Program     : Student Details

Description :
Reads the student's personal information from the
user and displays it in a formatted manner.

Concepts:
- Character Arrays
- User Input
- Formatted Output
- Variables

Author      : Vikas Raj
---------------------------------------------------------
*/
#include <stdio.h>

int main() {
    char rollNo[20]; //  roll numbers can be up to 20 characters
    char name[40]; //  name can be up to 40 characters
    char hostel[20]; // Assuming hostel names can be up to 20 characters
    int room;

    //  The user to enter the roll number
    printf("Enter your roll number: ");
    scanf("%s", rollNo);

    //  The user to enter your name
    printf("Enter your name: ");
    scanf("%s", name);

    //  The user to enter your hostel name
    printf("Enter your hostel name: ");
    scanf("%s", hostel);

    //  The user to enter your room number
    printf("Enter your room number: ");
    scanf("%d", &room);

    //  The details give by the user displays in this format
    printf("%s, %s\n", rollNo, name);
    printf("Room %d, %s Hostel\n", room, hostel);

    return 0;
}