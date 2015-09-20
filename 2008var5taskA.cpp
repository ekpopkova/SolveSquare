//var5taskA
#include <stdio.h>

int sumofnumbers (int N);
int input(const char name[], int* val);

int main()
{
    int N=0;
    if (!input("N", &N))
    {
        printf("Input error\n");
        return(0);
    }
    printf("Sum of ciphers of %d is %d", N, sumofnumbers(N));
    return(0);
}



int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int sumofnumbers (int N)
{
    int sum = 0;
    while (N>0)
    {
        sum = sum + N%10;
        N = N/10;
    }
    return(sum);
}
