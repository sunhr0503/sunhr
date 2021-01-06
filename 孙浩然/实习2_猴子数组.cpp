#include <stdio.h> 
#include <iostream>

using namespace std; 
void king(int m,int n)
{
    int p[m];
    int i,j,t;
    for (i=0; i<m; i++)         
        p[i]=1;
    t=-1;                       
    cout<<"出列顺序:";
    for (i=1; i<=m; i++)        //循环要执行m次，有m个猴子要出圈
    {
        j=1;      // j用于记录报数
        while(j<=n)  
        {
            t=(t+1)%m;        //很关键：看下一只猴子，到达最后时要折回去，所以用%m
            if (p[t]==1) j++; //等同于if (p[t]==1) j++;仅当q猴子在圈中，这个位置才报数
        }
        p[t]=0;   //猴子出圈
        cout<<t+1<<" ";                //输出出圈猴子的编号cout<<t+1; 
    }
    cout<<"\n"<<"大王："<<t+1;
    cout<<"\n";
}

int main()
{    int m,n;
	cout<<"猴子数:";
	cin>>m;
	cout<<"报数数:";
	cin>>n;
    king(m,n);
}

