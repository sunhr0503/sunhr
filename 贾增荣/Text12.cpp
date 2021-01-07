#include<stdio.h>
int main()
{
    int fun(int a,int b);
    int a,b,c;
    printf("Please enter a:\n");
    scanf("%d",&a);  
    printf("Please enter b:\n");
    scanf("%d",&b); 
    c=fun(a,b);
    printf("The number c is %d",c); 
    return 0;
}

int fun(int a,int b)
{
    int c1,c2,c3,c4; 
    c1=a%10;
    c2=b/10;
    c3=a/10;
    c4=b%10;
    return (1000*c1+c2+10*c3+100*c4);
}