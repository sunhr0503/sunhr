#include <iostream>
using namespace std;
int main()
{
	int M,N,i,j,c;
	cout<<"请输入行数M与N: "<<endl;
	cin>>M>>N;
	char a[100][100],b[100][100]={'A'};
	cout<<"请输入矩阵："<<endl;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			cin>>a[i][j];
	cout<<"请输入病毒周期c:"<<endl;
	cin>>c;
	while(c--)
	{
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)
				if(a[i][j]=='X')
					b[i][j]=a[i][j];
		for(i=0;i<M;i++)
			for(j=0;j<N;j++)
				if(a[i][j]==b[i][j])
				{
					if(a[i-1][j]!='P') a[i-1][j]='X';
					if(a[i][j-1]!='P') a[i][j-1]='X';
					if(a[i][j+1]!='P') a[i][j+1]='X';
					if(a[i+1][j]!='P') a[i+1][j]='X';
				}
	}
		for(i=0;i<M;i++)
		{
			cout<<endl;
			for(j=0;j<N;j++)
				cout<<a[i][j];
		}
		cout<<endl;
		return 0;
}