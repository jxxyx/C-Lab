#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// using the define function to ensure word may be up to 32 characters long.
#define MAX_WORD_LENGTH 32

typedef struct list_node {
    // defining variable to ensure that the null value is also able to be counted in
    char word[MAX_WORD_LENGTH + 1];
    struct list_node *next;
}LIST_NODE;

// Directing the LIST_NODE to a LIST_NODE_PTR
typedef LIST_NODE *LIST_NODE_PTR;

// Defining a void function to insert word in alphabetical order
void insertWord(LIST_NODE_PTR *head, const char* newWord) {
    LIST_NODE_PTR new_node = (LIST_NODE_PTR)malloc(sizeof(LIST_NODE));
    // this is a if function to check for memory allocation succession
    if (new_node == NULL) {
        fprintf(stderr, "Memory Allocation has failed!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->word, newWord);
    new_node->next = NULL;

    // Defining a preva
    LIST_NODE_PTR prev = NULL;
    LIST_NODE_PTR current = *head;

    // Find the correct position to insert the new word
    while (current != NULL && strcmp(new_node->word, current->word) > 0) {
        prev = current;
        current = current->next;
    }

    // Insert at the beginning
    if (prev == NULL) {
        new_node->next = *head;
        *head = new_node;
    } else {
        // Insert in the middle or at the end
        prev->next = new_node;
        new_node->next = current;
    }
}


// Function to free the memory allocated for the linked list
void freeList(LIST_NODE_PTR head) {
    while (head != NULL) {
        LIST_NODE_PTR temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to print the words in the linked list
void printList(LIST_NODE_PTR head) {
    while (head != NULL) {
        printf("%s\n", head->word);
        head = head->next;
    }
} 

int main() {
    LIST_NODE_PTR head = NULL;
    char userInput[MAX_WORD_LENGTH + 1];

    while (1) {
        printf("Please enter a word: ");
        scanf("%s", userInput);

        // Convert the word to lowercase
        for (int i = 0; userInput[i]; i++) {
            userInput[i] = tolower(userInput[i]);
        }

        // Check if the user wants to stop
        if (strcmp(userInput, "***") == 0) {
            break;
        }

        // Check if the word contains only valid characters
        for (int i = 0; userInput[i]; i++) {
            if (!islower(userInput[i]) && userInput[i] != '\'' && userInput[i] != '-') {
                fprintf(stderr, "Invalid character in the word. Please enter a valid word.\n");
                continue;
            }
        }

        // Insert the word into the linked list
        insertWord(&head, userInput);
    }

    // Print the sorted list
    printf("\nAll the entered words in order:\n");
    printList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}