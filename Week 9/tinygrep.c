#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 255

// perform a case-sensitive match between the given pattern and text.
// takes 2 parameter pattern and text
int match_case_sensitive(const char *pattern, const char *text) {
    // run a for loop to check each i in pattern   
    for (int i = 0; i < strlen(pattern); i++) {
        // checks if the i in pattern does not match the i in text.
        if (pattern[i] != text[i]) {
        return 0;
        }
    }
    // return 1 if the pattern matches text.
    return 1;
}

// perform a case-insensitive match between the given pattern and text.
// takes 2 parameter pattern and text
int match_case_insensitive(const char *pattern, const char *text) {
    // run a for loop for each i in pattern  
    for (int i = 0; i < strlen(pattern); i++) {
        // using if loop to check if patten i matches with text i
        if (tolower(pattern[i]) != tolower(text[i])) {
            return 0;
        }
    } 
    // return 1 if the pattern matches the case sensitivity of the text
    return 1;
}

// performs a match between the given pattern and text, handling dot and underscore characters.
// takes in 2 parameters pattern and text
int match_pattern(const char *pattern, const char *text, int case_sensitive) {
    // for loop to run through pattern until the end of pattern is reached  
    for (int i = 0; i < strlen(pattern); i++) {
        // if statement to look for .
        if (pattern[i] == '.') {
            // Dot matches any character.
            if (text[i] == '\0') {
            return 0;
        }
        } else if (pattern[i] == '_') {
        // Underscore matches any form of whitespace.
        if (!isspace(text[i])) {
            return 0;
        }
        } else {
        // All other characters match only themselves.
        // performs a case-insensitive comparison by converting both characters to lowercase using the tolower function and then comparing them
        if (case_sensitive && pattern[i] != text[i]) {
            return 0;
        } else if (!case_sensitive && tolower(pattern[i]) != tolower(text[i])) {
            return 0;
        }
        }
    }

  return 1;
}

int main() {
    // variable names
    char text[MAX_LENGTH];
    char pattern[MAX_LENGTH];
    int case_sensitive;

    // Read the input text and pattern.
    printf("Enter a line of text:\n");
    // This will get the text and check for the character length
    gets(text, MAX_LENGTH, stdin);

    printf("Enter a pattern:\n");
    // using fgets to read character into an array of char until a newline or end-of-file indicator is encountered
    fgets(pattern, MAX_LENGTH, stdin);

    // Convert the pattern and text to lowercase.
    for (int i = 0; i < strlen(pattern); i++) {
        pattern[i] = tolower(pattern[i]);
    }
    for (int i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }

    // Ask the user whether the match should be case-sensitive.
    printf("Should the match be case-sensitive (Y or N)?\n");
    case_sensitive = getchar();
    while (case_sensitive != 'Y' && case_sensitive != 'N') {
        rintf("Invalid input. Please enter Y or N.\n");
        case_sensitive = getchar();
    }

    // Perform the match.
    char *match = strchr(text, pattern[0]);
    if (match != NULL) {
        printf("Matches at position %d.\n", match - text);
    } else {
        printf("No match.\n");
    }

    return 0;
}