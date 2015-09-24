//var6taskD
#include <stdio.h>
#define MAXSIZE 100
#define DEFAULT -1

int input(const char name[], int* val);
int decompositions (int n, int k, int MemArr[], int arrsize);
void FillArray (int MemArr[], int arrsize);

int main()
{
    int N=0;
    int MemArr[MAXSIZE*MAXSIZE]={};
    if (!input("N", &N))
    {
        printf("INPUT ERROR\n");
        return 0;
    }
    else
    {
        FillArray (MemArr, N);
        printf("The number of decompositions of %d is %d\n", N, decompositions (N, N, MemArr, N));
    }
    return 0;

}
int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int decompositions (int n, int k, int MemArr[], int arrsize)
{
    if (MemArr[k+n*(arrsize+1)]!=DEFAULT)
        return MemArr[k+n*(arrsize+1)];
    else if (k>n)
    {
        MemArr[(k+n*(arrsize+1))] = decompositions (n, n, MemArr, arrsize);
        return MemArr[k+n*(arrsize+1)];
    }
    else
    {
        MemArr[(k+n*(arrsize+1))] = decompositions (n-k, k, MemArr, arrsize) + decompositions (n, k-1, MemArr, arrsize);
        return MemArr[k+n*(arrsize+1)];
    }
}

void FillArray (int MemArr[], int arrsize)
{
    for (int x=0; x<=arrsize; x++)
        for (int y=0; y<=arrsize; y++)
        {
            if ((x==0) && (y==0))
                MemArr[x+y*(arrsize+1)]=1;
            else if (x==0)
                MemArr[x+y*(arrsize+1)]=0;
            else
                MemArr[x+y*(arrsize+1)]=DEFAULT;

        }
}
