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
    cout<<"����˳��:";
    for (i=1; i<=m; i++)        //ѭ��Ҫִ��m�Σ���m������Ҫ��Ȧ
    {
        j=1;      // j���ڼ�¼����
        while(j<=n)  
        {
            t=(t+1)%m;        //�ܹؼ�������һֻ���ӣ��������ʱҪ�ۻ�ȥ��������%m
            if (p[t]==1) j++; //��ͬ��if (p[t]==1) j++;����q������Ȧ�У����λ�òű���
        }
        p[t]=0;   //���ӳ�Ȧ
        cout<<t+1<<" ";                //�����Ȧ���ӵı��cout<<t+1; 
    }
    cout<<"\n"<<"������"<<t+1;
    cout<<"\n";
}

int main()
{    int m,n;
	cout<<"������:";
	cin>>m;
	cout<<"������:";
	cin>>n;
    king(m,n);
}

