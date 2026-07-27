#include<bits/stdc++.h>
using namespace std;

void infix(string str)
{
    stack<char>stk;
    str='('+str+')';
    int len= str.size();
    for(int i=0;i<len;i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            cout<<str[i];
        }
        else if(str[i]=='(')
        {
            stk.push('(');
        }
        else if(str[i]==')')
        {
            while(stk.top()!='(')
            {
                cout<<stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if(str[i]=='+'|| str[i]=='-')
        {
            while(1)
            {
                char ch=stk.top();
                if(ch=='+'||ch=='-')
                {
                    break;
                }
                else if(ch=='(')
                {
                    break;
                }
                cout<<stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
         else if(str[i]=='*'|| str[i]=='/')
        {
            while(1)
            {
                char ch=stk.top();
                if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
                {
                    break;
                }
                else if(ch=='(')
                {
                    break;
                }
                cout<<stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
        else if(str[i]=='^')
        {
            stk.push(str[i]);
        }
    }
}
int main()
{
    cout<<"Enter the string: ";
    string str;
    cin>>str;
    cout<<"The expression of infix to postfix is:";
    infix(str);
    return 0;
}
