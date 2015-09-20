//var2taskC
#include <stdio.h>
#include <math.h>

int input(const char name[], int* val);
int is_prime(int a);
int find_prime (int n);

int main()
{
    int N=0;
    if (!input("N", &N)) printf("INPUT ERROR\n");
    else
    {
        printf("%dth prime number is %d", N, find_prime(N));
    }
    return 0;
}

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int is_prime(int a)
{
    int marker = 1;
    if (((a>10) && (a%5!=0)) || ((a<10) && (a>1)))
    {
        for (int i=2; i<(int)(sqrt(a)+1); i++)
        {
            if (a%i==0)
            {
                marker = 0;
                break;
            }
        }
    }
    else marker = 0;
return (marker);
}

int find_prime (int n)
{
    int currentprime=0, currentnumber=0;
    for (int i=2; currentnumber<n; i++)
    {
        if (is_prime(i))
        {
            currentnumber++;
            currentprime=i;
        }
    }
    return(currentprime);
}
