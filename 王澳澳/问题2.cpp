
/*����*/
#include <iostream>
#include <vector>
using namespace std;
const int N = 25;
//��ӡNֻ���ӵ�״̬����1����ʾ��Ȧ�ڣ���0����ʾ����Ȧ�ڣ�
void printVec(const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin();it != v.end();++it)
    {
        cout<<*it<<' ';
    }
    cout<<endl;
}
int monkeyKing(vector<int> v)
{
    //n��¼���ж���ֻ������Ȧ��
    int n = N;
    int k = 0;
    int i;
    while (n > 1)
    {
        for (i=0;i<N;++i)
        {
            k += v[i];
            if (k == 4)
            {
                v[i] = 0;
                printVec(v);
                k = 0;
                --n;
           }      }  }
    //���һֻ�����±�Ϊ1
    for (int i=0;i<N;++i)
    {
        if (1 == v[i])
            return i+1;
    }}
int main()
{
    vector<int> v(N,1);
    cout<<"������ǵ�"<<monkeyKing(v)<<"ֻ."<<endl;
    return 0;
}
/*����*/
#include <iostream>
using namespace std;
typedef struct test 
{
 int id;
 test *next;
};
test * newnode;
/*ɾ���󷵻ص�ǰ���*/
test* delete_node(test *headnode, test *deletenode)
{
   if (headnode->next == NULL)
      return NULL;
   test * f_head = headnode;
   test * f_head_next = f_head->next;
   while (f_head_next != NULL) 
   {
    if (f_head_next == deletenode) 
    {
     if (f_head_next->next == NULL) 
     {
      f_head->next = NULL;
      cout<<"Null ="<<headnode->id<<endl;
     }
     else
     {
        f_head->next = f_head_next->next;
        return f_head_next->next;
     }
     break;
    }
    f_head = f_head->next;
    f_head_next = f_head->next;
   }
}
// �����½��
test * addnode(test * node, int idnum)
{
 newnode = new test;
 newnode->id = idnum;
 newnode->next = NULL;
 node->next = newnode;
 return newnode; 
}
//����
void sort(test *head)
{
 if (head->next == NULL) 
       return;
 int temp;
 test * headnode = head;
 test * second = headnode->next;
 while (headnode != NULL) 
 {
  second = headnode->next;
  while (second != NULL) 
  { 
   if ((headnode->id )> (second->id))
   {
    temp = headnode->id;
    headnode->id = second->id;
    second->id = temp;
   }
   second = second->next;
  }  
  headnode = headnode->next;
 }
}
int main(void)
{
 cout<<"*******************begin**************"<<endl;
 test head;
    int nodenum = 0 ;
    test *temp = &head;
 test *currentNode = &head; //�˴������൱���м������Ϊ����ǰ���λ��
 test *before_node = head.next;
 bool ishead = false;
 cout<<"������������ֵ��"<<endl;   
 while (nodenum ++ != 30)
 {
     if (!ishead) 
  {
    head.id =nodenum;
    ishead = true;
       continue;
  }
  before_node = currentNode; /*����ָ���ǰһ��λ��*/
     currentNode = addnode(currentNode, nodenum);
 }
 sort(temp);
    temp = &head;
 int i = 1; 
 cout<<"�����ֵΪ��"<<endl;
 while (temp!= NULL)
 {
  cout<<"temp.id  "<<i<<" = "<< temp->id<<endl;
  temp = temp->next;
  i++;
 }
 /*β��ָ��ָ��ͷָ��*/
    currentNode->next = &head;   
 cout<<"*******************End**************"<<endl; 
    //before_node = delete_node(&head, before_node);
 //cout<<"new node = "<<before_node->id<<endl;
 /*��ʼѡ����*/
    temp = &head;
 i = 0;
 int node_num = 25;
 while (node_num != 1) 
 {
  i++;
  if (4 == i)
  {
   cout<<"ɾ�����Ϊ��"<<temp->id<<endl;
   temp = delete_node(&head, temp);
   i = 0;
   node_num--;
  }
  else
      temp = temp->next;
 }
 cout<<"������Ϊ:"<<temp->id<<endl;
    delete [] newnode;        //�ͷ�
 return 0;
}