#include<stdio.h>
void main(){
    int n,sum=0;
    printf("Enter a number:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    float avg=(float)sum/n;
    printf("Average of first %d numbers:%f",n,avg);
}