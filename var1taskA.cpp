//var1taskA
#include <stdio.h>
#include <math.h>

int is_simple(int a);
int input(const char name[], int* val);

int main()
{
    int N=0, k=0;
    if (!input("N", &N)) printf("INPUT ERROR/n");
    else
    {
        printf("enter your sequence> ");
        for (int i=0; i<N; i++)
        {
            if (!scanf("%d", &k)) printf("INPUT ERROR");
            else
                if (is_simple(k)) printf("%d ", k);
        }
    }
    return(0);
}



int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int is_simple(int a)
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


