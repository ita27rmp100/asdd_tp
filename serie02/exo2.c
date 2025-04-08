
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Sort the linked list
void sortList(Node** head) {
    if (!(*head) || !(*head)->next) return;

    for (Node* i = *head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                char temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Insert a character in sorted linked list
void insertSorted(Node** head, char data) {
    Node* newNode = createNode(data);
    if (!(*head) || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Reverse a singly linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Count character occurrences
void countCharacters(Node* head) {
    int counts[26] = {0};

    while (head) {
        if (isalpha(head->data)) {
            counts[tolower(head->data) - 'a']++;
        }
        head = head->next;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i]) {
            printf("%c: %d\n", i + 'a', counts[i]);
        }
    }
}

// Remove duplicates of a given character
void removeDuplicatesOfChar(Node** head, char target) {
    Node* current = *head;
    Node* prev = NULL;
    int found = 0;

    while (current) {
        if (current->data == target) {
            if (found) {
                prev->next = current->next;
                free(current);
                current = prev->next;
                continue;
            } else {
                found = 1;
            }
        }
        prev = current;
        current = current->next;
    }
}
