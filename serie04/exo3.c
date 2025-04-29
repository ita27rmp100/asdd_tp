#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 100

struct Node {
    int data;
    struct Node* next;
};

void reverse(struct Node** head_ref) {
    struct Node* first;
    struct Node* rest;
    if (*head_ref == NULL)
        return;
    first = *head_ref;
    rest = first->next;
    if (rest == NULL)
        return;
    reverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *head_ref = rest;
}
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node n3 = {3, NULL};
    struct Node n2 = {2, &n3};
    struct Node n1 = {1, &n2};
    struct Node* head = &n1;
    printf("Original list: ");
    printList(head);
    reverse(&head);
    printf("Reversed list: ");
    printList(head);

    return 0;
}