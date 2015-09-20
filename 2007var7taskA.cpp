//var7taskA
#include <stdio.h>
#define MAXDEGREE 32

int decimal_binary (int decimal[], int N);
int input(const char name[], int* val);
int power(int x, int y);

int main()
{
    int N, len;
    int decomposition[MAXDEGREE];
    if (!input("N", &N))
    {
        printf("input error\n");
        return (0);
    }
    else
    {
        printf("There is a following decomposition:\n");
        printf("%d = ", N);
        len=decimal_binary(decomposition, N);
        for (int i=0; i<len; i++)
        {
            if (decomposition[i])
                printf("%d + ", power(2,i));
        }
        printf("\b\b  ");
    }
    return(0);
}

int decimal_binary (int decimal[], int N)
{
    int i;
    for(i=0; N>=1; i++)
    {
        decimal[i] = N % 2;
        N /= 2;
    }
    return(i);
}

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int power(int x, int y)
{
    int res=1;
    for (int i=0; i<y; i++)
        res=res*x;
    return(res);
}

