#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int len,i,j,k,kk,check=0;

   while(1)
   {
        cout<<endl<<"Enter an string: ";
    cin>>str;
     len=str.size();

    for(i=0;i<len;i++)
    {
        if(str[i]=='|')
        {
            j=i;
            break;
        }
    }
    kk=j+1;

    for(k=0;k<j;k++,kk++)
    {
        if(str[k]!=str[kk])
        {
            check=1;
            break;
        }
    }
    if(check && k!=0)
    {
         cout<<"A->";
       for(i=0;i<k;i++)
      {
      cout<<str[i];
      }
      cout<<"A"<<endl;
      cout<<"A'->";
      if(k==j)
      {
          cout<<"#";
      }
      for(i=k;i<j;i++)
      {
          cout<<str[i];
      }
      cout<<"|";
      for(i=k+j+1;i<len;i++)
      {
          cout<<str[i];
      }

    }
    else
    {

        cout<<"A->";
        for(i=0;i<j+1;i++)
        {
            cout<<str[i];
        }
        cout<<"A'"<<endl;
        cout<<"A'->";
        for(i=j+1;i<len;i++)
        {
            cout<<str[i];
        }

    }
   }
}
