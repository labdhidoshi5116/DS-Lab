//Write a program to implement a Binary Search using Array. (Iterative & recursive)
//recursive method
#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] > target)
        return binarySearch(arr, low, mid - 1, target);
    else
        return binarySearch(arr, mid + 1, high, target);
}

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

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");
}