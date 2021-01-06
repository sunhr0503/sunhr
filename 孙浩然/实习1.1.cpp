#include<stdio.h>
int fun(int a,int b)
{
	int c;
	c=(a/10)*10+(a%10)*1000+(b/10)+(b%10)*100;
	
	return c;
}
int main()
{
	int a,b,d;
	
	scanf("%d",&a);
	scanf("%d",&b);
	
	d=fun(a,b);
	printf("%d",d);
}

