#include<stdio.h>
#include<stdlib.h>
void main(){
	int *a = (int *)malloc(sizeof(int)*5);
	float *b=(float *)malloc(sizeof(float));
	char *c=(char *)malloc(sizeof(char));
	if(a && b && c){
		*a=5;//this points to the value in pointer a
		*b=10.25;
		*c='A';
		free(a);//de-allocated memory
		free(b);//written inside if because the condition checked checkes if the variable holds a value or not
		free(c);
		printf("%d,%f,%c",*a,*b,*c);
	}
}

