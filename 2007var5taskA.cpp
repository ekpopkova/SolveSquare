//var5taskA
#include <stdio.h>
#define MY_EPSILON 0.0000001

double power(double x, int y);
int factorial (int n);
int inputint(const char name[], int* val);
int inputdoub(const char name[], double* val);

int main()
{
    double sum = 0;
    double x = 0;
    int N = 0;
    if (!inputint("N", &N))
    {
        printf("input error\n");
        return (0);
    }
    if (!inputdoub("x", &x))
    {
        printf("input error\n");
        return (0);
    }
    double part = 1;
    for (int k=0; k<=N && part>MY_EPSILON; k++)
    {
        part = (power(x, k)/factorial(k));
        sum = sum + part;
    }
    printf("for N = %d and x = %lg partial sum is %3.6f", N, x, sum);
}

double power(double x, int y)
{
    double res=1;
    for (int i=0; i<y; i++)
        res = res*x;
    return(res);
}

int factorial(int n)
{
    int res=1;
    for (int i=1; i<=n; i++)
        res = res*i;
    return(res);
}

int inputint(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int inputdoub(const char name[], double* val)
{
    printf("enter %s> ", name);
    if (!scanf("%lg", val)) return 0;
    else return 1;
}




