#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout<<"Enter an string:";
    cin>>str;
    int i,j,k,len,flag=0;
    len=str.size();
    for(i=0;i<len;i++)
    {
        if(str[i]!='a')
        {
          j=i-1;
          break;
        }
    }
    for( i=len-1;i>=0;i--)
    {
        if(str[i]!='b')
        {
            k=i+1;
            break;
        }
    }ab
    if(j>=0 && k<len && j+1==k )
    {
        flag=1;
    }
    if(flag==1)
    {
        cout<<"Grammar is accepted";
    }
    else
    {
        cout<<"Not accepted";
    }

    return 0;
}
