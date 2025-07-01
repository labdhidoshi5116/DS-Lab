#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, *ptr, max,i;
	printf("Enter number of elements: ");
    scanf("%d", &n);
    ptr = (int*) malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
    }
	printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }
	max = *ptr;
	for (i = 1; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }
	printf("Largest element = %d\n", max);
	free(ptr);
}

