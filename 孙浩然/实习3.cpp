#include <iostream>

using namespace std; 

typedef struct student{
	int num;
	int yw;
	int sx;
	int yy;
	int sum;
}stu ;
int main()
{
	int n;
	cout<<"ѧ������:";
	cin>>n;
	stu a[n];
	stu temp;
	for(int i=0;i<n;i++)
	{
		a[i].num=i+1;
		cout<<"ѧ�ţ�"<<a[i].num<<"\n"; 
		cout<<"���ĳɼ���";
		cin>>a[i].yw;
		cout<<"��ѧ�ɼ���";
		cin>>a[i].sx;
		cout<<"Ӣ��ɼ���";
		cin>>a[i].yy;
		a[i].sum=a[i].yw+a[i].sx+a[i].yy;
		cout<<"�ܷ�"<<a[i].sum<<"\n";
	}
	for(int p=0;p<n;p++)
	{
    	for(int j=0;j<n-p;j++)
    	{
		    if(a[j].sum<a[j+1].sum)
		    {
		    	temp=a[j];
			    a[j]=a[j+1];
			    a[j+1]=temp;
			}
		    if(a[j].sum==a[j+1].sum&&a[j].yw<a[j+1].yw)
		    {
		    	temp=a[j];
		    	a[j]=a[j+1];
		    	a[j+1]=temp;
			}
		    if(a[j].sum==a[j+1].sum&&a[j].yw==a[j+1].yw&&a[j].num>a[j+1].num)
		    {
		    	temp=a[j];
		    	a[j]=a[j+1];
		    	a[j+1]=temp;
			}
		
	    }
    }
    if(n<5)
    {
    	for(int q=0;q<n;q++)
    {
    	cout<<"ѧ�ţ�"<<a[q].num<<" "
    	    <<"�ܷ֣�"<<a[q].sum<<"\n";
	}
	}
	
	if(n>=5)
    {
    	for(int q=0;q<n;q++)
    {
    	cout<<"ѧ�ţ�"<<a[q].num<<" "
    	    <<"�ܷ֣�"<<a[q].sum<<"\n";
	}
	}
	
	
	
	
	
	
	
	
}
