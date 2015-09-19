//var3taskA
#include <stdio.h>

int recurs_GSD (int a, int b);
int input(const char name[], int* val);
int LCM_with_GCD (int a, int b);

int main()
{
    int a=0, b=0, c=0;
    printf("Enter numers to calculate LCM\n");
    if (!input("a", &a))
    {
        printf("Input error: wrong symbol for a\n");
        return 0;
    }
    if (!input("b", &b))
    {
        printf("Input error: wrong symbol for b\n");
        return 0;
    }
    if (!input("c", &c))
    {
        printf("Input error: wrong symbol for c\n");
        return 0;
    }
    printf("LCM (%d, %d, %d) = %d", a, b, c, LCM_with_GCD(LCM_with_GCD(a,b),c));
    return 0;
}

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int recurs_GSD (int a, int b)
{
	return b ? recurs_GSD(b, a % b) : a;
}

int LCM_with_GCD (int a, int b)
{
	return a*b/recurs_GSD(a, b);
}

