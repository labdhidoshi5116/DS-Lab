//Write a program to implement a Binary Search using Array. (Iterative & recursive)
//iterative method
#include <stdio.h>

void main() {
    int n, target, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, mid;
    int flag = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            flag = 1;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!flag) {
        printf("Element not found in the array.\n");
    }
}