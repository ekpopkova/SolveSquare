//var8taskB
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int getline(char s[], int lim);

int main()
{
    char line[MAXLINE];
    int len=0, digits=0, alphas=0;
    printf("Enter you line here:\n");
    len=getline(line, MAXLINE);
    if (!len)
    {
        printf ("Empty line\n");
        return(0);
    }
    for (int i=0; i<len; i++)
    {
        if (isalpha(line[i])) alphas++;
        if (isdigit(line[i])) digits++;
    }
    printf("there are %d digits and %d letters", digits, alphas);
    return(0);
}

int getline(char s[], int lim)
{
    int c=0, i=0;
    for (i=0; (i<lim-1) && ((c=getchar())!=EOF) && (c!='\n'); ++i)
        s[i]=c;
    if (c=='\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return (i);
}
