//var4taskC
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int getline(char s[], int lim);
void revers (char s[], int begining, int ending);
int findnextalpha (char s[], int laststop);

int main()
{
    char line[MAXLINE];
    int len=0, mem=0;
    printf("Enter you line here:\n");
    len=getline(line, MAXLINE);
    if (!len) printf ("Empty line\n");
    else
    {
        for (int i=0; i<len; i++)
        {
           if (!isalpha(line[i]))
           {
               revers(line, mem, i);
               mem=findnextalpha (line, i);
           }
        }
    printf("Here is the result> %s", line);
    }
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

void revers (char s[], int begining, int ending)
{
    char Buf;
    for (int i=begining; i<int(begining+((ending-begining)/2)); i++)
    {
        Buf = s[i];
        s[i] = s[ending-i+begining-1];
        s[ending-i+begining-1] = Buf;
    }
}

int findnextalpha (char s[], int laststop)
{
    int i;
    for (i=laststop; !isalpha(s[i]); i++)
        ;
    return(i);
}
