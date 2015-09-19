//var1taskC
#include <stdio.h>
#define CHASHA 4

int recursia_weight (int a);
int input(const char name[], int* val);

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int recursia_weight (int a)
{
    int k;
    if (a==1)
        return(1);
    else
    {
        k=a%CHASHA;
        if ((k==0) || (k==1) || (k==3))
            return (recursia_weight((a/CHASHA)));
        else return(0);
    }
}

int main()
{
    int N;
    if (!input("N", &N))
        printf("input error");
    if (recursia_weight(N))
        printf("YES");
    else printf("NO");
    return(0);

}
