#include<bits/stdc++.h>
using namespace std;
string str;
int i,error=0;
void E();
void Eds();
void T();
void Tds();
void F();
int main()
{
    cout<<"Enter an string:";
    cin>>str;
    E();
    if(i==str.size() && error ==0)
    {
        cout<<"String is accepted";
    }
    else
    {
        cout<<"String rejected";
    }
    return 0;
}
void E()
{
    T();
    Eds();
}
void Eds()
{
    if(str[i]=='+')
    {
        i++;
        T();
        Eds();
    }
}
void T()
{
    F();
    Tds();
}
void Tds()
{
    if(str[i]=='*')
    {
        i++;
        F();
        Tds();
    }
}
void F()
{
    if(str[i]=='a'||str[i]=='b'||str[i]=='c')
    {
        i++;
    }
    else if(str[i]=='(')
    {
         i++;
        E();
        if(str[i]==')')
            i++;
        else
            error=1;
    }
    else
        error=1;
}
