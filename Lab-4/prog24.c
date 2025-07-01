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
    int inrep,elerep;
    printf("Enter the index of element you want to replace:");
    scanf("%d",&inrep);
    printf("Enter the element you want to insert:");
    scanf("%d",&elerep);
    for(int i=n;i>inrep;i--){
        a[i]=a[i-1];
    }
    a[inrep]=elerep;
    printf("New Array");
    for(int i=0;i<=n;i++){
        printf("%d,",a[i]);
    }
}