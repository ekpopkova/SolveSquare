//var10taskC
#include <stdio.h>
#define MAXSIZE 100000

void sorting (int arrtosort[], int len);
int input(const char name[], int* val);
int inputarray (const char name[], int arr[], int arrsize);

int main()
{
    int N;
    int sequence[MAXSIZE];
    if (!input("a number of elements in your sequence", &N))
    {
        printf("INPUT ERROR\n");
        return(0);
    }
    if (!inputarray ("enter your sequence ", sequence, N))
    {
        printf("INPUT ERROR\n");
        return(0);
    }
    sorting (sequence, N);
    if (sequence[1]!=sequence[0]) printf ("%d ", sequence[0]);
    for (int i=1; i<N; i++)
        if ((sequence[i]!=sequence[i-1]) && (sequence[i]!=sequence[i+1]))
            printf ("%d ", sequence[i]);
    return(0);
}


void sorting (int arraytosort[], int len)
{
   int t = 0, Buf;
   for(int i = 0; i < len; ++i)
   {
      if(arraytosort[i] < arraytosort[t])
         t = i;
   }
   Buf = arraytosort[0];
   arraytosort[0]=arraytosort[t];
   arraytosort[t]=Buf;
   if(len > 1)
      sorting(arraytosort + 1, len - 1);
}

int input(const char name[], int* val)
{
    printf("enter %s> ", name);
    if (!scanf("%d", val)) return(0);
    else return(1);
}

int inputarray (const char name[], int arr[], int arrsize)
{
    printf("%s> ", name);
    for (int i=0; i<arrsize; i++)
    {
        if (!scanf("%d", &arr[i]))
        {
            return(0);
            break;
        }
    }
    return(1);
}
