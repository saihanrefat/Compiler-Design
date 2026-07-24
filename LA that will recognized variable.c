#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *kw[]={"int","float","double","char","long"};

int iskw(char *w)
{
    for(int i=0;i<5;i++)
    {
        if(strcmp(kw[i],w)==0)
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

    int ch,i,flag=0;
    char w[50];

    while((ch=fgetc(f))!=EOF)
    {
        if(isalpha(ch))
        {
            i=0;

            while(isalnum(ch) || ch=='_')
            {
                w[i++]=ch;
                ch=fgetc(f);
            }

            w[i]='\0';

            if(iskw(w))
            {
                flag=1;
                printf("%s variables : ",w);
            }
            else if(flag)
            {
                if(ch=='(')       // Function (main) হলে Skip
                {
                    flag=0;
                    printf("\n");
                }
                else
                {
                    printf("%s",w);

                    if(ch==',')
                        printf(",");
                }
            }
        }

        if(ch==';')
        {
            flag=0;
            printf("\n");
        }
    }

    fclose(f);
    return 0;
}
