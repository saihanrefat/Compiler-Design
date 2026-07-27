#include<stdio.h>
#include<string.h>
#include<ctype.h>
char *kw[]={"int","float","double","char","long","return","switch","case","do","constant","goto","default","typedef"};
int iskw(char *w)
{
    for(int i=0;i<13;i++)
    {
      if(!strcmp(kw[i],w))
      {
          return 1;
      }
    }
    return 0;
}
int main()
{
    FILE *f=fopen("source.c","r");
    if(f==NULL)
    {
        printf("File is not open");
        return 1;
    }
    int ch,flag=0,first=0;
    char temp[20];
    while((ch=fgetc(f))!=EOF)
    {
        if(isalpha(ch))
        {
            char variable[20];
            int i=0;
            while(isalnum(ch)|| ch=='_')
            {
                variable[i++]=ch;
                ch=fgetc(f);
            }
            variable[i]='\0';
            if(iskw(variable))
            {
               flag=1;
               first=1;
               strcpy(temp,variable);
            }
            else if(flag)
            {
                while(ch==' '|| ch=='\n'|| ch=='\t')
                {
                    ch=fgetc(f);
                }
                if(ch=='(')
                {
                    flag=0;
                    continue;
                }
                if(first)
                {
                    printf("%s variables: %s\n",temp,variable);
                }
                else
                {
                    printf(", %s",variable);
                }
            }
        }
        if(ch==';')
        {
            flag=0;
            cout<<endl;
        }
    }
    fclose(f);
    return 0;
}

