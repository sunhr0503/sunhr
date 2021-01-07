
/*数组*/
#include <iostream>
#include <vector>
using namespace std;
const int N = 25;
//打印N只猴子的状态（“1”表示在圈内，“0”表示不在圈内）
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
    //n记录还有多少只猴子在圈内
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
    //最后一只猴子下标为1
    for (int i=0;i<N;++i)
    {
        if (1 == v[i])
            return i+1;
    }}
int main()
{
    vector<int> v(N,1);
    cout<<"猴大王是第"<<monkeyKing(v)<<"只."<<endl;
    return 0;
}
/*链表*/
#include <iostream>
using namespace std;
typedef struct test 
{
 int id;
 test *next;
};
test * newnode;
/*删除后返回当前结点*/
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
// 增加新结点
test * addnode(test * node, int idnum)
{
 newnode = new test;
 newnode->id = idnum;
 newnode->next = NULL;
 node->next = newnode;
 return newnode; 
}
//排序
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
 test *currentNode = &head; //此处变量相当于中间变量，为链表当前结点位置
 test *before_node = head.next;
 bool ishead = false;
 cout<<"请输入链表结点值："<<endl;   
 while (nodenum ++ != 30)
 {
     if (!ishead) 
  {
    head.id =nodenum;
    ishead = true;
       continue;
  }
  before_node = currentNode; /*保存指针的前一个位置*/
     currentNode = addnode(currentNode, nodenum);
 }
 sort(temp);
    temp = &head;
 int i = 1; 
 cout<<"链表的值为："<<endl;
 while (temp!= NULL)
 {
  cout<<"temp.id  "<<i<<" = "<< temp->id<<endl;
  temp = temp->next;
  i++;
 }
 /*尾部指针指向头指针*/
    currentNode->next = &head;   
 cout<<"*******************End**************"<<endl; 
    //before_node = delete_node(&head, before_node);
 //cout<<"new node = "<<before_node->id<<endl;
 /*开始选大王*/
    temp = &head;
 i = 0;
 int node_num = 25;
 while (node_num != 1) 
 {
  i++;
  if (4 == i)
  {
   cout<<"删除结点为："<<temp->id<<endl;
   temp = delete_node(&head, temp);
   i = 0;
   node_num--;
  }
  else
      temp = temp->next;
 }
 cout<<"最后大王为:"<<temp->id<<endl;
    delete [] newnode;        //释放
 return 0;
}