#include<stdio.h>
void main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    int rep1,rep2;
    printf("Enter the number to be replaced and the new number:");
    scanf("%d %d",&rep1,&rep2);
    for(int i=0;i<n;i++){
        if(a[i]==rep1){
            a[i]=rep2;
        }
    }
    printf("New Array:");
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
}