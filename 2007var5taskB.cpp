//var5taskB
#include <stdio.h>
#include <math.h>

int input(const char name[], int* val);
int divisors (int N);


int main()
{
    int N=0;
    if (!input("N", &N)) printf("INPUT ERROR\n");
    else
    {
        printf("sum of divisors of %d is %d", N, divisors(N));
    }
    return(0);
}


int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int divisors(int N)
{
    int sum = 0;
    for (int i=1; i<(sqrt(N)+1); i++)
    {
        if (N % i == 0)
        {
            sum = sum + i;
            if (i != N/i) sum =sum + N/i;
        }
    }
    return(sum);
}


