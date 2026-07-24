#include<stdio.h>
#include<ctype.h>

int main()
{
    FILE *input = fopen("source.c","r");
    FILE *output = fopen("output.c","w");

    if(input==NULL || output==NULL)
    {
        printf("File not found");
        return 1;
    }

    int ch;
    char num[50];
    int i;

    while((ch = fgetc(input)) != EOF)
    {
        // Remove space and tab
        if(ch==' ' || ch=='\t')
            continue;

        // Collect numbers (integer and float)
        if(isdigit(ch))
        {
            i = 0;

            while(isdigit(ch) || ch=='.')
            {
                num[i++] = ch;
                fputc(ch, output);
                ch = fgetc(input);
            }

            num[i] = '\0';
            printf("%s\n", num);

            if(ch != EOF)
                ungetc(ch, input);
        }
        else
        {
            fputc(ch, output);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}
