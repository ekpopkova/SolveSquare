//var9taskC
#include <stdio.h>
#define MAXSIZE 1001

void binary_sum (int a, int b, int *mem, int *res, int memor);
void outputarr (int arr[], int len);
int maximum (int a, int b);
int createarr (int arr[]);
void revers (int s[], int begining, int ending);

int main()
{
    int number1[MAXSIZE] = {0}, number2[MAXSIZE] = {0}, result[MAXSIZE]={0};
    printf("enter the first number> ");
    int len1 = createarr(number1);
    printf("enter the second number> ");
    int len2 = createarr(number2);
    int mem = 0;
    int M=maximum(len1, len2);
    revers(number1, 0, len1);
    revers(number2, 0, len2);
    for (int i=0; i<=M; i++)
    {
        binary_sum(number1[i], number2[i], &mem, &result[i], mem);
    }
    revers(result, 0, M+1);
    printf(" The result is: ");
    outputarr (result, M+1);
}

void revers (int s[], int begining, int ending)
{
    int Buf;
    for (int i=begining; i<int(begining+((ending-begining)/2)); i++)
    {
        Buf = s[i];
        s[i] = s[ending-i+begining-1];
        s[ending-i+begining-1] = Buf;
    }
}

void binary_sum(int a, int b, int *mem, int *res, int memor)
{
    *res = (a+b+memor)%2;
    int k = (a+b+memor)/2;
    *mem = k;
}

int maximum (int a, int b)
{
    if (a>b) return (a);
    else return(b);
}

void outputarr (int arr[], int len)
{
    int marker = 0;
    for (int i=0; i<len; i++)
    {
        if (marker == 0)
        {
            if (arr[i]==1)
            {
                 printf("%d", arr[i]);
                 marker = 1;
            }
        }
        else printf("%d", arr[i]);
    }
}

int createarr (int arr[])
{
    int i;
    char c;
    for (i=0; (c=getchar())!='\n'; i++)
        if (c=='1')
        {
            arr[i]=1;
        }
        else if (c=='0')
        {
            arr[i]=0;
        }
        else
        {
            return(0);
            break;
        }
    return(i);
}
