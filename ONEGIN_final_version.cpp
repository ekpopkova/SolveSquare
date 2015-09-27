#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <locale>

#define FILEREAD "eugen_onegin.txt"
#define FILEWRITE "eugen_onegin_new.txt"

//D in the end of a name of a funclion means, that it deals with dynamic store

const int OK = 0;
const int OS_FAULT = 2;
const int FILE_ERROR = 3;
const int SEEK_ERROR = 4;


int readfileD(const char* filename, char* buffer[], int* len);
char** split_linesD(char* buffer, int len, int* nline);
int make_file(const char* filename, char** text, int nline);
int mlStrcmp(const char* str1, const char* str2);
void simplesort(char** lines, int len);

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("This is assorting of %s\n", FILEREAD);
    int len = 0;
    char* buffer;
    if (readfileD(FILEREAD, &buffer, &len))
    {
        printf("INPUT ERROR\n");
    }
    int nline = 0;
    char** text = split_linesD(buffer, len, &nline);
    simplesort(text, nline);
    make_file(FILEWRITE, text, nline);
    free(text[0]);
    free(text);
    return OK;
}

int readfileD(const char* filename, char* buffer[], int* len)
{
    assert(buffer);
    assert(len);
    FILE* OriginalText = fopen(filename, "rb");
    if (!OriginalText)
        return FILE_ERROR;
    fseek(OriginalText, 0, SEEK_END);
    *len = ftell (OriginalText);
    if (!*len)
        return SEEK_ERROR;
    rewind(OriginalText);
    char* tempbuffer = (char*)calloc(*len, sizeof(*tempbuffer));
    assert(tempbuffer);
    fread(tempbuffer, sizeof(*tempbuffer), *len, OriginalText);
    fclose(OriginalText);
    *buffer = tempbuffer;
    return OK;
}

char** split_linesD(char* buffer, int len, int* nline)
{
    assert(nline);
    assert(*nline == 0);
    assert(buffer);
    for (int i = 0; i < len; i++)
    {
        assert (0<=i && i<len);
        if (buffer[i] == '\r')
            {
                (*nline)++;
                buffer[i] = '\0';
            }
    }

    char** text = (char**)calloc(*nline, sizeof(*text));
    assert(text);
    text[0] = buffer;
    int j = 1;
    for (int i = 0; i+ OS_FAULT < len - 1; i++)
        if (buffer[i] == '\0')
        {
            assert (0<=i && i+OS_FAULT<len);
            text[j] = &buffer[i+OS_FAULT];
            j++;
            assert(1<=j && j<=(*nline));
        }
    return text;
}

int mlStrcmp(const char* str1, const char* str2)
{
        int size1 = strlen(str1);
        int size2 = strlen(str2);
        int i;
        int j;
        for (i = size1-1; isalpha(str1[i]) == 0 ; i--)
            ;
        for (j = size2-1;   isalpha(str2[j]) == 0; j--)
            ;
        while (str1[i] == str2[j])
        {
            i--;
            j--;
            if ((i == 0) || (j == 0)) return 0;
        }
        return str1[i] - str2[j];
}

int make_file(const char* filename, char** text, int nline)
{
    assert(text);
    FILE* NewText = fopen(filename, "wb");
    if (!NewText)
        return FILE_ERROR;
    for (int i = 0; i < nline; i++)
    {
        assert(0<=i && i<nline);
        if (text[i][0] != '\0')
        {
            fprintf (NewText, "%s\n", text[i]);
        }
    }
    fclose(NewText);
    return OK;
}

void simplesort(char** text, int len)
{
    char* temp;
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < len - i - 1; j++)
            if (mlStrcmp(text[j], text[j + 1]) > 0)
            {
                temp = text[j];
                text[j] = text[j + 1];
                text[j + 1] = temp;
            }
 }
