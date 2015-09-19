//var 1 task B
#include <stdio.h>
#include <math.h>


int free_from_sqr (int a);
int input(const char name[], int* val);

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

int main()
{
    int N;
    if (!input("N", &N))
        printf("input error");
    if (free_from_sqr(N))
        printf("YES");
    else printf("NO");
    return 0;
}
