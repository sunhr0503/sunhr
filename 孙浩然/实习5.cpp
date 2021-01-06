#include <iostream>
#include <cstdlib>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
struct Stack{
char*base;
char*top;
int stacksize;
};
struct DStack{
double*base;
double*top;
int stacksize;
};
double Evaluateexpression_r(char m[]);
int InitStack(Stack&S);
int InitDStack(DStack&S);
int Push(Stack &S,char e);
int DPush(DStack &S,double e);
int Pop(Stack &S,char &e);
int DPop(DStack &S,double &e);
char GetTop(Stack &S);
double DGetTop(DStack &S);
double Operate(double a, char theta, double b);
int In(char c);
char Precede(char c1,char c2);//��������

int main(){
cout<<"������ʽ�����ʽ��=����"<<endl;
char m[50];
cin>>m;
double c;
c=Evaluateexpression_r(m);
cout<<"���������ʽ�Ľ��Ϊ"<<c<<endl;
return 0;
}

double Evaluateexpression_r(char m[]) { //�������ʽ��ֵ��OPTR��OPDN�ֱ�Ϊ�����ջ�Ͳ�����ջ
Stack OPTR;   
DStack OPND;
   InitStack (OPTR);
   Push (OPTR, '=');
   InitDStack (OPND);
   double a , b;
   int i=0;
char c,theta;
while( m[i]!='=' || GetTop(OPTR) !='=' )
{
   if( !In(m[i]) )      
   {
    char *p;
   p=&m[i];
   while(!In(m[i])||m[i]=='.'){i++;}
   DPush(OPND,atof(p));
   }
   else
      switch( Precede(GetTop(OPTR) , m[i] ) )
    {
    case '<':
    Push(OPTR,m[i]);
    i++;
    break;

    case '=':
    Pop(OPTR,c);
    i++;
    break;
           case '>':
    Pop(OPTR,theta);
    DPop(OPND,b);
    DPop(OPND,a);
    DPush(OPND,Operate(a , theta , b));
    break;
    
    }
   }
return DGetTop(OPND) ;
}
int InitStack(Stack&S) //���������ջ
{
S.base = new char[STACK_INIT_SIZE] ;
if(!S.base) cout<<"����ʧ��"<<endl;
S.top = S.base;
S.stacksize = STACK_INIT_SIZE;
return 1;
}
int InitDStack(DStack&S) //���������ջ
{
S.base = new double[STACK_INIT_SIZE];
if(!S.base) cout<<"����ʧ��"<<endl;
S.top = S.base;
S.stacksize = STACK_INIT_SIZE;
return 1;
}

int Push(Stack &S,char e)//�������ջ
{
if(S.top-S.base>=S.stacksize){
S.base=new char[S.stacksize+STACKINCREMENT];
    if(!S.base) cout<<"����ʧ��"<<endl;
S.top=S.base+S.stacksize;
S.stacksize+=STACKINCREMENT;
}
    *S.top++ = e;
    return 1;

}
int DPush(DStack &S,double e)//��������ջ
{
if(S.top-S.base>=S.stacksize){
S.base=new double[S.stacksize+STACKINCREMENT];
    if(!S.base) cout<<"����ʧ��"<<endl;
S.top=S.base+S.stacksize;
S.stacksize+=STACKINCREMENT;
}
    *S.top++ = e;
    return 1;
}
int Pop(Stack &S,char &e)//�������ջ
{
if (S.top==S.base)return 0;
e=*--S.top;
return 1;
}
int DPop(DStack &S,double &e)//��������ջ
{
if (S.top==S.base)return 0;
e=*--S.top;
return 1;
}
char GetTop(Stack &S)//�����������ջ��Ԫ��
{
char e;
if(S.top==S.base)return 0;
e=*(S.top-1);
return e;
}
double DGetTop(DStack &S)//���ز�������ջ��Ԫ��
{
double e;
if(S.top==S.base)return 0;
e=*(S.top-1);
return e;
}
double Operate(double a,char theta, double b) {//����
   switch(theta) {
     case '+': return a+b;break;
     case '-': return a-b;break;
     case '*': return a*b;break;
     case '/': if(b!=0) {return a/b;break;}
         else cout<<"��ĸ����Ϊ�㣡,�������"<<endl;
   default: return 0;
}
}
int In(char c){//�ж��Ƿ�Ϊ������
if(c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='('&&c!=')'&&c!='=') return 0;
else return 1;
}
char Precede(char c1,char c2){//�Ƚ������֮������ȼ�
switch(c1){
case '+':if(c2=='+'||c2=='-'||c2==')'||c2=='=') return '>';
    else return '<';break;
case '-':if(c2=='+'||c2=='-'||c2==')'||c2=='=') return '>';
    else return '<';break;
case '*':if(c2=='(') return '<';
    else return '>';break;
case '/':if(c2=='(') return '<';
    else return '>';break;
case '(':if(c2==')') return '=';
          else return '<';break;
case ')': return '>';break;
case '=':if(c2=='=') return '=';
          else return '<';break;
default:return 0;
}
}
