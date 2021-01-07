#include <iostream>
#include <string>
#include <stack>
using namespace std;
double calculate(string s)
{
    stack<double> num;
    stack<char> op;
    string temp = "";
    for(int i = 0; i < s.length(); i++)
    {
     if(s[i] >= '0' && s[i] <= '9')
        {
            temp += s[i];
        }
        if((s[i] < '0' || s[i] > '9') && temp != "")
        {
            num.push(atoi(temp.c_str()));
            temp = "";
        }
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            op.push(s[i]);
        }
        if(s[i] == '*' || s[i] == '/')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                if(lastop == '/')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    num.push(firstnum*1.0/secondnum);
                    op.pop();
                }
            }
            op.push(s[i]);
        }
        if(s[i] == '+' || s[i] == '-')
        {
            if(i == 0 || s[i-1] == '(' || s[i-1] == '[' || s[i-1] == '{')
            {
                num.push(0);
            }
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && (lastop == '*' || lastop == '/'))
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    if(lastop == '*')
                        num.push(firstnum*secondnum);
                    else if(lastop == '/')
                        num.push(firstnum*1.0/secondnum);
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '-')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    num.push(firstnum-secondnum);
                    op.pop();
                }
            }
            op.push(s[i]);
        }
        if(s[i] == ')')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && lastop != '(')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    switch(lastop)
                    {
                        case '+':
                            num.push(firstnum+secondnum);
                            break;
                        case '-':
                            num.push(firstnum-secondnum);
                            break;
                        case '*':
                            num.push(firstnum*secondnum);
                            break;
                        case '/':
                            num.push(firstnum*1.0/secondnum);
                            break;
                    }
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '(')
                    op.pop();
            }
        }
        if(s[i] == ']')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && lastop != '[')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    switch(lastop)
                    {
                        case '+':
                            num.push(firstnum+secondnum);
                            break;
                        case '-':
                            num.push(firstnum-secondnum);
                            break;
                        case '*':
                            num.push(firstnum*secondnum);
                            break;
                        case '/':
                            num.push(firstnum*1.0/secondnum);
                            break;
                    }
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '[')
                    op.pop();
            }
        }
        if(s[i] == '}')
        {
            if(!op.empty())
            {
                char lastop = op.top();
                while(!op.empty() && lastop != '{')
                {
                    double secondnum = num.top();
                    num.pop();
                    double firstnum = num.top();
                    num.pop();
                    switch(lastop)
                    {
                        case '+':
                            num.push(firstnum+secondnum);
                            break;
                        case '-':
                            num.push(firstnum-secondnum);
                            break;
                        case '*':
                            num.push(firstnum*secondnum);
                            break;
                        case '/':
                            num.push(firstnum*1.0/secondnum);
                            break;
                    }
                    op.pop();
                    if(!op.empty())
                        lastop = op.top();
                }
                if(lastop == '{')
                    op.pop();
            }
        }
    }
    if(temp != "")
        num.push(atoi(temp.c_str()));
    while(!op.empty())
    {
         char lastop = op.top();
         double secondnum = num.top();
         num.pop();
         double firstnum = num.top();
         num.pop();
         switch(lastop)
         {
             case '+':
                 num.push(firstnum+secondnum);
                 break;
             case '-':
                 num.push(firstnum-secondnum);
                 break;
             case '*':
                 num.push(firstnum*secondnum);
                 break;
             case '/':
                 num.push(firstnum*1.0/secondnum);
                 break;
         }
         op.pop();
    }
    if(num.empty())
        return 0;
    double value = num.top();
    num.pop();
    return value;
}
void test1()
{
    string s;
    while(cin >> s)
    {
        cout << calculate(s) << endl;
    }
}

int main()
{
    test1();
    return 0;
}