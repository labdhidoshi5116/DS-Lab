#include<stdio.h>
void main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int a[n+1];
    for(int i=0;i<n;i++){
        printf("Enter element:");
        scanf("%d",&a[i]);
    }
    int ins;
    printf("Enter the element to be inserted:");
    scanf("%d",&ins);
    a[n]=ins;
    for(int i=0;i<n;i++){
        for(int j=0;j<=n;j++){
            if(a[j+1]>a[j]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted Array");
    for(int i=0;i<=n+1;i++){
        printf("%d ",a[i]);
    }
}