#include<bits/stdc++.h>
using namespace std;

int check(string str)
{
    if(str=="int"||str=="float"||str=="double"||str=="long"||str=="char")
        return 1;
    else
        return 0;
}
int main()
{
    FILE *fp=fopen("source.cpp","r");
    if(fp==NULL)
    {
        cout<<"File is not open";
        return 0;
    }
    char word[100];
    while(fscanf(fp,"%s",word)!=EOF)
    {
       if(check(word))
       {
            cout<<word<<" variables: ";
        char ch;
        int k=0;
        while((ch=fgetc(fp))!=EOF)
        {
            if(ch==';')
                break;
            if(ch=='=')
            {
               k=1;
               continue;
            }
            if(ch==',')
            { cout<<",";
                k=0;
                continue;
            }
            if(k==0&& ch !=' ')
            {
                cout<<ch;
            }
        }
       }
        cout<<endl;
    }
    fclose(fp);
    return 0;
}


