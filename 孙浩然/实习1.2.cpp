#include<iostream>
 
using namespace std;


int fun(int& a,int& b)
{
	int c;
	c=(a/10)*10+(a%10)*1000+(b/10)+(b%10)*100;
	
}
int main()
{
	int x,y;
	cin>>x;
	cin>>y;
	int d=fun(x,y);
	cout<<d;
} 
	
