//var6taskA
#include <stdio.h>

const int MAXSIZE = 50;
// FIXME: why lowercase and swapping? Function is an action - then Swap
void swaping (int *a, int *b);
void PrintArray (int Array[][MAXSIZE], int Xsize, int Ysize);
void MirrowArray (int Array[][MAXSIZE], int Xsize, int Ysize);
int InputArray ( const char name[], int Array[][MAXSIZE], int Xsize, int Ysize);
int input(const char name[], int* val);

int main()
{
    int Xsize = 0, Ysize = 0;
    int MainArray[MAXSIZE][MAXSIZE] = {};
    if (!input("length of your matrix", &Xsize))
    {
        printf("INPUT ERROR\n");
        return 0;
    }
    if (!input("width of your matrox", &Ysize))
    {
        printf("INPUT ERROR\n");
        return 0;
    }
    if (!InputArray ("your sequence line by line", MainArray, Xsize, Ysize))
    {
        printf("INPUT ERROR\n");
        return 0;
    }
    MirrowArray (MainArray, Xsize, Ysize);
    PrintArray (MainArray, Xsize, Ysize);
    return 0;

}

void swaping (int *a, int *b)
{
// FIXME: Always check pointers. Somehow a or b may be NULL.
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void PrintArray (int Array[][MAXSIZE], int Xsize, int Ysize)
{
    for (int y = 0; y < Ysize; y++)
        for (int x = 0; x < Xsize; x++)
        {
            if (x == Xsize-1)
                printf("%d\n", Array[y][x]);
            else
                printf("%d\t", Array[y][x]);
        }
}

void MirrowArray (int Array[][MAXSIZE], int Xsize, int Ysize)
{
// FIXME: add assert checks for array bounds. It's hard to maintain indicies corectness
    for (int x = 0; x < Xsize; x++)
        for (int y = 0; y < (Ysize/2); y++)
            swaping(&Array[y][x], &Array[Ysize-y-1][x]);
    for (int y = 0; y < Ysize; y++)
        for (int x = 0; x < (Xsize/2); x++)
            swaping(&Array[y][x], &Array[y][Xsize-x-1]);
}

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return 0;
    else return 1;
}

int InputArray (const char name[], int Array[][MAXSIZE], int Xsize, int Ysize)
{
    printf("enter %s>\n", name);
    int marker = 1;
    for (int y = 0; y < Ysize; y++)
        for (int x = 0; x < Xsize; x++)
        {
            marker = (marker + scanf("%d", &Array[y][x]))/2; // FIXME: Whaaat?
        }
    return marker;
}
