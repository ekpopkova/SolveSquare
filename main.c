#include <stdio.h>
#include <math.h>
#include <float.h>

#define INFINITE_ROOTS -1

int input(const char name[], double* val);
int SolveSquare(double a, double b, double c, double *x1, double *x2);
int output(int nRoots, double a, double b, double c, double x1, double x2);
int equaltozero (double a);

int main()
{
    printf("Solve Squared Equation v1 by Katja\n");
    printf("Enter a, b, c for ax^2 + bx + c = 0\n");
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
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
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    output(nRoots, a, b, c, x1, x2);
    return 0;
}

int equaltozero (double a)
{
    if ((a < DBL_EPSILON) && (a > -DBL_EPSILON))
        return (1);
    else return (0);
}

int input(const char name[], double* val)
{
    printf("enter %s>", name);
    if (!scanf("%lg", val)) return 0;
    else return 1;
}

int SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    int nRoots = 3;
    double D = (b*b - 4*a*c);


    if (fabs(a) > DBL_EPSILON)
    {
        if (D > DBL_EPSILON)
        {
            *x1 = ((sqrt(D) - b) / (2*a));
            *x2 = ((- sqrt(D) - b) / (2*a));
            nRoots = 2;
        }
        else if (equaltozero (D))
        {
            *x1 = ((-b) / 2*a);
            nRoots = 1;
        }
        else nRoots = 0;
    }
    else
    {
        if (fabs(b) > DBL_EPSILON)
        {
            *x1 = -c / b;
            nRoots = 1;
        }
        else
        {
            if (c == 0) nRoots = INFINITE_ROOTS;
            else nRoots = 0;
        }
    }
    return nRoots;
}

int output(int nRoots, double a, double b, double c, double x1, double x2)
{
    switch (nRoots)
    {
        case INFINITE_ROOTS:
            printf("Equation %lg*x^2 + %lg*x + %lg = 0 has infinite set of roots", a, b, c);
            break;
        case 0:
            printf("Equation %lg*x^2 + %lg*x + %lg = 0 has no roots", a, b, c);
            break;
        case 1:
            printf("Equation %lg*x^2 + %lg*x + %lg = 0 has one real root x = %lg\n", a, b, c, x1);
            break;
        case 2:
            printf("Equation %lg*x^2 + %lg*x + %lg = 0 has two real roots: x1 = %lg, x2 = %lg\n", a, b, c, x1, x2);
            break;
        case 3:
            printf("ERROR");
            break;
    }
    return 0;
}

