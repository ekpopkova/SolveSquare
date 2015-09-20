//var4taskB
//I don't know how to make this code easier to understand:
//by writing numbers of symbols in define (as with sharp), by writing it like space and tabulation (' ', '\t'),
//or by using their numbers (as with punctuation marks)
//what would you advise?
#include <stdio.h>
#include <ctype.h>
#define sharp 35

int filtrsymbol (int symb);

int main()
{
    int c=0, mem=0;
    printf("Enter your text here:\n");
    while ((c=getchar())!=EOF)
    {
        if (((mem==' ') || (mem=='\t')) && ((c==' ') || (c=='\t')))
            c=0;
        else
        {
            c=filtrsymbol(c);
            mem=c;
        }
        if (c!=0) putchar(c);
    }
    return(0);
}

int filtrsymbol (int symb)
{
    if (isalpha(symb))
    {
        if (isupper(symb)) symb=tolower(symb);
        return (symb);
    }
    else if (isdigit(symb)) symb = sharp;
    else if ((symb==33) || (symb==34) || (symb==39) || (symb==58) || (symb==59) || (symb==63) || ((symb>=44) && (symb<=46)))
             symb = 0;
    return (symb);
}
