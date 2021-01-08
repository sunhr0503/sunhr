#include<iostream>
using namespace std;
int change(int &a,int &b)
{
	int c1,c2,c3,c4;
    c1=a%10;
    c2=b/10;
    c3=a/10;
    c4=b%10;
    return (c1*1000+c2*100+c3*10+c4);
}
int main()
{
    int a,b,c;
	cout<<"请输入a,b的值:  "<<endl;
	cin>>a>>b;
	c=change(a,b);
    cout<<"合并后a,b的值:  "<<c<<endl;
}
