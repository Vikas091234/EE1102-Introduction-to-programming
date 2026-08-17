/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 8
Program     : Custom getline()

Description :
Implements a custom getline() function to read
text files line by line while removing the
trailing newline character.

Author      : Vikas Raj
---------------------------------------------------------
*/

// File name: ROLLNO_readfile_getline.c

#include <stdio.h>

// Custom function to read a line from a file and remove
// the newline character if present.
// NOTE: Named ROLLNO_getline() to avoid conflict with POSIX getline().
int ROLLNO_getline(char *line, int max, FILE *iop);

int main() {
    FILE *filePointer;
    char fileName[100];
    char buffer[1000];  // Buffer to hold each line (max length 1000)

    // Ask user for the name of the file to open
    printf("Enter the file name: ");
    scanf("%s", fileName);

    // Try opening the file in read mode
    filePointer = fopen(fileName, "r");

    // Check if fopen() succeeded
    if (filePointer == NULL) {
        printf("Error opening file %s\n", fileName);
        return 1;   // Return non-zero to indicate failure
    }

    // Read and print each line using our custom getline function
    while (ROLLNO_getline(buffer, sizeof(buffer), filePointer) > 0) {
        printf("%s\n", buffer);    // Print the line without newline
    }

    // Close the file once done
    fclose(filePointer);

    return 0;   // Program ended successfully
}

// ----------------------------------------------------------------------
// Function: ROLLNO_getline()
// Purpose : Read a single line from the file into 'line'.
//           Removes the trailing newline ('\n') if present.
// Returns : Length of the line (after removing newline).
//           Returns 0 if EOF is reached.
// ----------------------------------------------------------------------
int ROLLNO_getline(char *line, int max, FILE *iop) {

    // fgets() returns NULL if EOF or an error occurs
    if (fgets(line, max, iop) == NULL) {
        return 0;   // No more lines to read
    }

    int length = 0;

    // Manually calculate length until null terminator or newline
    while (line[length] != '\0' && line[length] != '\n') {
        length++;
    }

    // If the last character was a newline, remove it
    if (line[length] == '\n') {
        line[length] = '\0';
    }

    return length;   // Return length of the processed line
}
