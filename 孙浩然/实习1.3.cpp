#include<iostream>
 
using namespace std;

int fun(int* a,int* b)
{
	int c;
	c=(*a/10)*10+(*a%10)*1000+(*b/10)+(*b%10)*100;
	return c;
	
}

int main()
{
	int x;
	int y;
	cin>>x>>y;
    
    int* p=&x;
    int* q=&y;
	//cin>>*x;
	//cin>>*y;
	int d=fun(p,q);
	cout<<d;
}
