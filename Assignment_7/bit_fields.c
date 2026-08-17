/*
---------------------------------------------------------
Course      : EE1102 - Introduction to Programming
Assignment  : 7
Program     : Bit-Field String Manipulation

Description :
Performs different string transformations based
on a user-specified bit mask, including case
conversion, capitalization, and word reversal.

Author      : Vikas Raj
---------------------------------------------------------
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 100

void remove_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && s[n-1] == '\n') s[n-1] = '\0';
}

void to_upper(char s[]) {
    for (size_t i = 0; s[i]; ++i) s[i] = (char) toupper((unsigned char)s[i]);
}

void to_lower(char s[]) {
    for (size_t i = 0; s[i]; ++i) s[i] = (char) tolower((unsigned char)s[i]);
}

void capitalize_words_keep_rest(char s[]) {
    int start_word = 1;
    for (size_t i = 0; s[i]; ++i) {
        if (isspace((unsigned char)s[i])) {
            start_word = 1;
        } else {
            if (start_word && isalpha((unsigned char)s[i])) {
                s[i] = (char) toupper((unsigned char)s[i]);
            }
            start_word = 0;
        }
    }
}


void capitalize_words_lower_rest(char s[]) {
    int start_word = 1;
    for (size_t i = 0; s[i]; ++i) {
        if (isspace((unsigned char)s[i])) {
            start_word = 1;
        } else {
            if (start_word && isalpha((unsigned char)s[i])) {
                s[i] = (char) toupper((unsigned char)s[i]);
            } else {
                s[i] = (char) tolower((unsigned char)s[i]);
            }
            start_word = 0;
        }
    }
}


void reverse_letters_in_words(char s[]) {
    size_t i = 0;
    while (s[i]) {
        
        while (s[i] && isspace((unsigned char)s[i])) ++i;
        if (!s[i]) break;
        size_t start = i;
        while (s[i] && !isspace((unsigned char)s[i])) ++i;
        size_t end = i - 1;
        // reverse [start..end]
        while (start < end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            ++start; --end;
        }
    }
}

int modifyString(char str[], int mask) {
    if (!str) return -1;

    switch (mask) {
        case 0:
            // no-op
            break;
        case 1:
            to_upper(str);
            break;
        case 2:
            to_lower(str);
            break;
        case 4:
            capitalize_words_keep_rest(str);
            break;
        case 6:
            capitalize_words_lower_rest(str);
            break;
        case 8:
            reverse_letters_in_words(str);
            break;
        default:
            return 1; 
    }
    return 0;
}

int main(void) {
    char str[MAXLEN];
    int mask;

    printf("Enter a string: ");
    if (!fgets(str, sizeof str, stdin)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }
    remove_newline(str);

    printf("Enter a mask (0, 1, 2, 4, 6, or 8): ");
    if (scanf("%d", &mask) != 1) {
        fprintf(stderr, "Invalid mask input\n");
        return 1;
    }

    if (modifyString(str, mask) != 0) {
        printf("Invalid mask. No modification performed.\n");
        return 1;
    }

    printf("Modified string: %s\n", str);
    return 0;
}
