//var 1 task B
#include <stdio.h>
#include <math.h>


int free_from_sqr (int a);
int input(const char name[], int* val);

int main()
{
    int N;
    if (!input("N", &N))
    {
        printf("input error\n");
        return (0);
    }
    else
    {
        if (free_from_sqr(N))
            printf("There are full squares in decomposition of %d", N);
        else printf("There are no full squares in decomposition of %d", N);
        return (0);
    }
}

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int free_from_sqr (int a)
{
    int marker = 0, mem = 0, i = 2;
    while (i<=(int)(sqrt(a)+1))
    {
        if (a%i==0)
        {
            if (mem==i)
            {
                marker = 1;
                break;
            }
            mem = i;
            a=a/i;
        }
        else i++;
    }
    return(marker);
}


