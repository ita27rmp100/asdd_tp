#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//recursive
int MaxRec(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int max = MaxRec(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}
//iterative
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
int main(){
    int arr[] = {5, 1, 9, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Max using recursion: %d\n", MaxRec(arr, size));
    printf("Max using goto: %d\n", MaxGoto(arr, size));

    return 0;
}