#include<stdio.h>
void main(){
    int m,n,sum=0;
    printf ("Enter starting and ending point:");
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++){
        sum+=i;
    }
    printf("Sum from %d to %d is:%d",m,n,sum);
}