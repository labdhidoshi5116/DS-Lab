// The ASCII value for the lowercase letter "a" is 97. The ASCII value for the uppercase letter "A" is 65
#include<stdio.h>
void main(){
	char c;
	printf("Enter a character:");
	scanf(" %c",&c);
	if(c>=A && c<=Z)
	{
		c=c+32;
	}
	if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u')
	{
		printf("Is a vowel");
	}
	else{
		printf("Is not a vowel");
	}
}
