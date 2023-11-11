#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

typedef struct grade_node {
    char surname[20];
    double grade;
    struct grade_node *next;
} GRADE_NODE;

typedef GRADE_NODE *GRADE_NODE_PTR;

// Function to display the linked list
void displayList(GRADE_NODE_PTR head) {
    GRADE_NODE_PTR current = head;

    while (current != NULL) {
        printf("Surname: %s, Grade: %.2f\n", current->surname, current->grade);
        current = current->next;
    }
}

int main() {
    // Declaring a pointer that will be called head to start the node with a null value
    GRADE_NODE_PTR head = NULL;

    // Using the term of malloc to do up a dynamic array
    GRADE_NODE_PTR new_node = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
    strcpy(new_node->surname, "Adams");
    new_node->grade = 85.0;
    new_node->next = head;
    head = new_node;

    // 2nd Node 
    GRADE_NODE_PTR new_node1 = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
    strcpy(new_node1->surname, "Pritchard");
    new_node1->grade = 66.5;
    new_node1->next = NULL;

    // This node will be placed at the end of the list 
    if (head == NULL) {
        head = new_node1;
    } else {
        GRADE_NODE_PTR current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node1;
    }

    // 3rd Node to put in between 1st and 2nd node
    GRADE_NODE_PTR new_node2 = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
    strcpy(new_node2->surname, "Jones");
    new_node2->grade = 91.5;
    new_node2->next = NULL;

    GRADE_NODE_PTR prev = NULL;
    GRADE_NODE_PTR current = head;

    while (current != NULL && strcmp(current->surname, new_node2->surname) < 0) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        // Insert at the beginning
        new_node2->next = head;
        head = new_node2;
    } else {
        // Insert in the middle or at the end
        prev->next = new_node2;
        new_node2->next = current;
    }

    // Display the linked list
    displayList(head);

    return 0;
}