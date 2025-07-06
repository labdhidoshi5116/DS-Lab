#include<stdio.h>
#include<stdlib.h>
void main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(int j=0;j<n;j++){
        printf("Enter element %d: ", j+1);
        scanf("%d",&a[j]);
    }
    int *ptr;
    ptr=a;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0; j < n - i - 1; j++)
{
            if(*(ptr+j)>*(ptr+j+1)){
                int temp=*(ptr+j);
                *(ptr+j)=*(ptr+j+1);
                *(ptr+j+1)=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ", *(ptr+i));
    }
}