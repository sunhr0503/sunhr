#include <iostream>
#include <string.h>

using namespace std;
int main()
{
	int m=4,n=10,c;
//	int j;
    char a[m][n]={"OOOOOPOOOO",
	              "OXOOOPOOOO",
	              "OOOOOPOOOO",
	              "OOOOOPOOOO"};
	char b[m][n]=
	             {"OOOOOOOOOO",
	              "OOOOOOOOOO",
	              "OOOOOOOOOO",
	              "OOOOOOOOOO"}; 
	/*cout<<"�У�����";
	cin>>m; 
	cout<<"�У�������";
	cin>>n;
	for(int i=0;i<m;i++)
	{
		//cout<<"��"<<i+1<<"��:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"��"<<j+1<<"��:" ;
			cin>>a[i][j];
		}
		
		cout<<"\n";
	} */
	for(int i=0;i<m;i++)
	{
		//cout<<"��"<<i+1<<"��:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"��"<<j+1<<"��:" ;
			cout<<a[i][j];
		}
		
		cout<<"\n";
	} 
	cout<<"\n";
	
	
	
	for(int u;u<6;u++)
	{
	for(int i=0;i<m;i++)
	{
		//cout<<"��"<<i+1<<"��:" ;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='P'||a[i][j]=='X')
			{
				//cout<<i<<","<<j<<"\n";
				b[i][j]=a[i][j];
			}
			//if()	
		}	
	}
	
		for(int i=0;i<m;i++)                     ///������ֳ 
	{
		//cout<<"��"<<i+1<<"��:" ;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='X'&&i!=0&&j!=0)
			{
				b[i+1][j]='X';
				b[i-1][j]='X';
				b[i][j+1]='X';
				b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&i==m-1&&j==0)
			{
				//cout<<i<<","<<j<<"\n";
				//b[i+1][j]='X';
				b[i-1][j]='X';
				b[i][j+1]='X';
				//b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&i==m-1&&j==n-1)
			{
				//cout<<i<<","<<j<<"\n";
				//b[i+1][j]='X';
				b[i-1][j]='X';
				//b[i][j+1]='X';
				b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&i==0&&j==n-1)
			{
				//cout<<i<<","<<j<<"\n";
				b[i+1][j]='X';
				//b[i-1][j]='X';
				//b[i][j+1]='X';
				b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&i==0&&j==0)
			{
				//cout<<i<<","<<j<<"\n";
				b[i+1][j]='X';
				//b[i-1][j]='X';
				b[i][j+1]='X';
				//b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&i==0&&j!=0&&j!=n-1)
			{
				//cout<<i<<","<<j<<"\n";
				b[i+1][j]='X';
				//b[i-1][j]='X';
				b[i][j+1]='X';
				b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&i==m-1&&j!=0&&j!=n-1)
			{
				//cout<<i<<","<<j<<"\n";
				//b[i+1][j]='X';
				b[i-1][j]='X';
				b[i][j+1]='X';
				b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&j==0&&i!=0&&i!=m-1)
			{
				//cout<<i<<","<<j<<"\n";
				b[i+1][j]='X';
				b[i-1][j]='X';
				b[i][j+1]='X';
				//b[i][j-1]='X';
			}
			if(a[i][j]=='X'&&j==n-1&&i!=0&&i!=m-1)
			{
				//cout<<i<<","<<j<<"\n";
				b[i+1][j]='X';
				b[i-1][j]='X';
				//b[i][j+1]='X';
				b[i][j-1]='X';
			}
			if(a[i+1][j]=='P')
			{
				b[i+1][j]='P';
			}
			if(a[i-1][j]=='P')
			{
				b[i-1][j]='P';
			}
			if(a[i][j+1]=='P')
			{
				b[i][j+1]='P';
			}
			if(a[i][j-1]=='P')
			{
				b[i][j-1]='P';
			}
			
			
			//if()	
			
		}	
	}
	for(int i=0;i<m;i++)                       ///b���鴫��a���� 
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=b[i][j];
		}
	}
	
	
	cout<<"��"<<u+1<<"��"<<"\n" ;
	for(int i=0;i<m;i++)//shuchub                 ///ÿ�η�ֳ���� 
    {
        	
		//cout<<"��"<<i+1<<"��:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"��"<<j+1<<"��:" ;
			cout<<b[i][j];
		}
		cout<<"\n";
	}  
	
    }
	
	/*for(int i=0;i<m;i++)//shuchub
    {
        	
		//cout<<"��"<<i+1<<"��:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"��"<<j+1<<"��:" ;
			cout<<b[i][j];
		}
		cout<<"\n";
	}  */ 
	
}




