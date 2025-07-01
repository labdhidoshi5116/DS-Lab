#include<>stdio.h>
void main()
{
	int sec,h,m,s;
	printf("enter a sec:");
	scanf("%d",&sec);
	h=sec/3600;
	m=(sec-(h*3600))/60;
	s=sec-(m*60)-(h*3600);
	printf("%d :%d :%d",h,m,s);
	return 0;
}
