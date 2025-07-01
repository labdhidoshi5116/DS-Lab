#include<stdio.h>
void  main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    int del_in;
    printf("Enter the index of the element to be deleted:");
    scanf("%d",&del_in);
    for(int i=del_in;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
    printf("New Array");
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
}