#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

int main(){
    char word[] = "madam";
    printf("Is \"%s\" a palindrome? %s\n", word, isPalindrome(word) ? "Yes" : "No");
    return 0;
}