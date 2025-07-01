#include<stdio.h>
void main(){
    int n,maxin,minin;
    printf("enter number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter a number:");
        scanf("%d",&a[i]);
    }
    int max=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
            maxin=i;
        }
    }
    int min=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<min){
            min=a[i];
            minin=i;
        }
    }
    printf("Maximum at index %d \n",maxin);
    printf("Minimum at index %d \n",minin);
}