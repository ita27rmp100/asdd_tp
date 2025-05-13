#include <stdio.h>
#include <string.h>

//exo1: Recursive exponentiation
int power(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

//exo2: dec to bin using recursion
void DecToBin(int n) {
    if (n == 0)
        return;
    DecToBin(n / 2);
    printf("%d", n % 2);
}

//exo3:recursion reverse de LLL
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
// fonction supplementaire pour afficher le contenu de LLC 
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// exo4
int isPalindromeHelper(char str[], int start, int end) {
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return isPalindromeHelper(str, start + 1, end - 1);
}
int isPalindrome(char str[]) {
    int len = strlen(str);
    return isPalindromeHelper(str, 0, len - 1);
}
//exo5 : max val in arr
    // recursive
int MaxRec(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int max = MaxRec(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}
    // iterative with goto
int MaxGoto(int arr[], int n) {
    int i = 0;
    int max = arr[0];
    start:
        if (i >= n) goto end;
        if (arr[i] > max)
            max = arr[i];
        i++;
        goto start;
    end:
        return max;
}

int main() {
    // Test 01
    printf("Power(2, 5): %d\n", power(2, 5));
    // Test 02
    int num = 10;
    printf("Binary of %d: ", num);
    if (num == 0) printf("0");
    else DecToBin(num);
    printf("\n");
    // Test Exercise 03
    struct Node n3 = {3, NULL};
    struct Node n2 = {2, &n3};
    struct Node n1 = {1, &n2};
    struct Node* head = &n1;
    printf("Original list: ");
    printList(head);
    reverse(&head);
    printf("Reversed list: ");
    printList(head);
    // Test Exercise 04
    char word[] = "madam";
    printf("Is \"%s\" a palindrome? %s\n", word, isPalindrome(word) ? "Yes" : "No");
    // Test Exercise 05
    int arr[] = {5, 1, 9, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Max using recursion: %d\n", MaxRec(arr, size));
    printf("Max using goto: %d\n", MaxGoto(arr, size));

    return 0;
}