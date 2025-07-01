#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	srand(time(0));//to change the value of random everytime as random doesn't change everytime we run the program
	int n,i,j;
	printf("Enter the number of Words:");
	scanf("%d",&n);
	char b[n][100],ana[100];
	for(i=0;i<n;i++){
		printf("Enter word at %d place:",(i+1));
		scanf("%s",b[n]);
	}
	int a=rand()%n;
	printf("Random Number:%d",a);
	printf("Enter the anagram of %s",b[a]);
	scanf("%s",ana);
	char temp1[100],temp2[100];
	strcpy(temp1,b[a]);
	strcpy(temp2,ana);
	int len1=strlen(temp1);
	int len2=strlen(temp2);

	if(len1!=len2){
		
	}

}
