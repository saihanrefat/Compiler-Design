#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *kw[]={"switch","if","else", "char","int","float","double","long","case","const","continue","default","do",
           "for","goto","return","register","signed","unsigned","return","static","short","sizeof","struct","typedef"
           ,"union","void","volatile","while","void","enum","extern"};

int iskw(char *w)
{
    for(int i=0;i<32;i++)
    {
        if(!strcmp(w,kw[i]))
        return 1;
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
    int ch,i;
    char num[50];
    while((ch=fgetc(f))!=EOF)
    {
        if(isalpha(ch))
        {
            i=0;
            while(isalnum(ch))
            {
              num[i++]=ch;
              ch=fgetc(f);
            }
            num[i]='\0';
            if(iskw(num))
            {
                printf("%s\n",num);
            }
        }
    }

    fclose(f);
}
