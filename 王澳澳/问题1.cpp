/*1��ͨ������ֵ������c������������*/
#include<stdio.h>
int main()
{ int fun(int a,int b);
int a,b,c;
printf("Please enter a:\n");
scanf("%d",&a); //����������a
printf("Please enter b:\n"); scanf("%d",&b); //����������b
c=fun(a,b);
printf("The number c is %d",c); //���������c
return 0; }
int fun(int a,int b)
{ int c1,c2,c3,c4; //c1��c2��c3��c4�ֱ��Ӧc��ǧλ����λ��ʮλ����λ
c1=a%10;
c2=b/10;
c3=a/10;
c4=b%10;
return (c1*1000+c2*100+c3*10+c4);
}
/*2��ͨ�����ò���������������������*/
#include<stdio.h>
int fun(int a, int b)
{
    int a1,a10,b1,b10,c;
    a10=a/10;
    a1=a%10;
    b10=b/10;
    b1=b%10;
    c=a1*1000+b1*100+a10*10+b10*1;
    return c;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d",fun(m,n));
    return  0;
}
/*3��ͨ��ָ���Ͳ���������������������*/
#include "stdio.h" 
int fun(int  *x,int  *y) 
{ 
 int t,m,n,o; 
 t=*x/10; 
 m=*x%10;
 n=*y/10; 
 o=*y%10;
 return (m*1000+o*100+t*10+n);  
}
int main() 
{ 
  int a,b,y; 
  printf("������a��b��"); 
  scanf("%d%d",&a,&b); 
  y=fun(&a,&b); 
  printf("\n\ta = %d",y); 
}