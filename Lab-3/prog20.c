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
    int dup=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                printf("Duplicate found:%d at %d and %d\n",a[i],i,j);
                dup=1;
            }
        }
    }
    if(!dup){
        printf("No duplicates found");
    }
    
}