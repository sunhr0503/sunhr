#include <iostream.h>

typedef struct Node{
    int data;
    struct Node *next;
}NODE;

int _f6_main()  
{

    NODE *head,*s,*q,*t;
    int n,m,count=0,i;
    cout<<"����ѡ������/n";
    cout<<"��������Ӹ���n,m��"<<endl;
    cout<<"n=";
    cin>>n;
    cout<<"/nm=";
    cin>>m;


    for(i=1;i<=n;i++){
        s=new NODE;
        s->data=i;
        s->next=NULL;
        if(i==1){head=s,q=head;}
           else
           {
            q->next=s;
            q=q->next;
           }
    }
    q->next=head;
    cout<<"/n����ǰ��";
    q=head;
    while(q->next!=head)
    {
        cout<<q->data<<" ";
        q=q->next;
    }
    cout<<q->data;
    cout<<"/n���Ӻ�";
    q=head;
    do
    {
        count++;
        if(count==m-1)
        {
            t=q->next;
            q->next=t->next;
            count=0;
            cout<<t->data<<" ";
        }
        q=q->next;
    }while(q->next!=q);
    cout<<q->data<<endl;

return 0;

}