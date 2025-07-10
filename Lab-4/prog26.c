#include<stdio.h>
void main()
{
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    int a[n+1],temp, ins;
    for(int i=0; i<n; i++)
    {
        printf("Enter a element:");
        scanf("%d",& a[i]);
    }

    printf("Enter the number to be inserted:");
    scanf("%d",& ins);
    int i;
    for( i=0; i<n && a[i]<ins;i++);

    temp = i;
   for( i=n; i>=temp; i--)
    {
        a[i]=a[i-1];
    }
    a[temp]=ins;
    for(int j=0; j<n+1; j++)
    {
        printf("%d \n",a[j]);
    }
}