//var8taskB
#include <stdio.h>
#include <math.h>

int is_square(int n);
int input(const char name[], int* val);

int main()
{
    int N=0, k=0;
    if (!input("N", &N)) printf("INPUT ERROR\n");
    else
    {
        printf("enter your sequence> ");
        for (int i=0; i<N; i++)
        {
            if (!scanf("%d", &k)) printf("INPUT ERROR\n");
            else
                if (is_square(k)) printf("%d ", k);
        }
    }
    return(0);
}

int is_square(int n)
{
    for (int i=1; i<(int)(sqrt(n)+1); i++)
        if (i*i==n)
        {
            return (1);
            break;
        }
    return (0);
}

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

