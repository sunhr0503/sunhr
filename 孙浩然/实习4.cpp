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
	/*cout<<"行（宽）：";
	cin>>m; 
	cout<<"列（长）：";
	cin>>n;
	for(int i=0;i<m;i++)
	{
		//cout<<"第"<<i+1<<"行:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"第"<<j+1<<"列:" ;
			cin>>a[i][j];
		}
		
		cout<<"\n";
	} */
	for(int i=0;i<m;i++)
	{
		//cout<<"第"<<i+1<<"行:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"第"<<j+1<<"列:" ;
			cout<<a[i][j];
		}
		
		cout<<"\n";
	} 
	cout<<"\n";
	
	
	
	for(int u;u<6;u++)
	{
	for(int i=0;i<m;i++)
	{
		//cout<<"第"<<i+1<<"行:" ;
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
	
		for(int i=0;i<m;i++)                     ///病毒繁殖 
	{
		//cout<<"第"<<i+1<<"行:" ;
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
	for(int i=0;i<m;i++)                       ///b数组传给a数组 
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=b[i][j];
		}
	}
	
	
	cout<<"第"<<u+1<<"次"<<"\n" ;
	for(int i=0;i<m;i++)//shuchub                 ///每次繁殖结束 
    {
        	
		//cout<<"第"<<i+1<<"行:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"第"<<j+1<<"列:" ;
			cout<<b[i][j];
		}
		cout<<"\n";
	}  
	
    }
	
	/*for(int i=0;i<m;i++)//shuchub
    {
        	
		//cout<<"第"<<i+1<<"行:" ;
		for(int j=0;j<n;j++)
		{
			//cout<<"第"<<j+1<<"列:" ;
			cout<<b[i][j];
		}
		cout<<"\n";
	}  */ 
	
}




