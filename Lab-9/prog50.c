#include<stdio.h>
#include<stdlib.h>
void main(){
    int n, *arr,i;
	printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int*) malloc(n * sizeof(int));
	if (arr == NULL) {
        printf("Memory not allocated.\n");
    }
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);//we don't have the address of the first element and so we add i to it for the increament
    }
    printf("Array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    free(arr);
}


