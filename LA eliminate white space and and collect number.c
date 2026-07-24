#include<stdio.h>
int main()
{
    FILE *input=fopen("source.c","r");
     FILE *output=fopen("output.c","w");
     if(input==NULL || output ==NULL)
     {
         printf("File is not open");
         return 1;
     }
     printf("The numbers are:\n");
     int ch;
     int i;
     char num[50];
     while((ch=fgetc(input))!=EOF)
     {
         if(ch==' '|| ch=='\t')
            continue;
         if(isdigit(ch))
         {
             i=0;
             while(isdigit(ch)|| ch=='.')
             {
                 num[i++]=ch;
                 fputc(ch,output);
                 ch=fgetc(input);
             }
             num[i]='\0';
             printf("%s\n",num);
             ungetc(ch,input);
         }
         else{
            fputc(ch,output);
         }
     }
     fclose(input);
     fclose(output);
}
