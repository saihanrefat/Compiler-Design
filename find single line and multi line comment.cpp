#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    printf("Enter an string:");
    getline(cin,str);
    if(str.find("//")==0)
    {
        printf("It is a single line commment");
    }
    else if(str.find("/*")==0 && str.find("*/")!=string::npos)
    {
         printf("It is a multi line commment");
    }
    else{
        printf("No linr comment.");
    }
}

