#include<iostream>
using namespace std;
int combine(int *a,int*b)
{
  int c,c1,c2,c3,c4;
	c1=*a%10;
    c2=*b/10;
    c3=*a/10;
    c4=*b%10;
    c=(c1*1000+c2*100+c3*10+c4);
	return c;
}
int main()
{
  int *a,*b;
  int c,d,e;
  cout<<"请输入a,b的值: "<<endl;
  cin>>c>>d;
  a=&c;
  b=&d;
  e=combine(a,b);
  cout<<"合并后的a,b值为: "<<e<<endl;
}
