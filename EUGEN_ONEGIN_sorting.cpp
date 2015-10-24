#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <locale>

#define MY_DEBUG
#ifdef MY_DEBUG
    #define ASSERT_OK(type, what)                                                                                   \
        if (!type ## _OK (what))                                                                                          \
        {                                                                                                                          \
            type ## _dump(what);                                                                                         \
            printf("failed in %s, %s, line number %d", __FILE__, __PRETTY_FUNCTION__, __LINE__);  \
            abort();                                                                                                             \
        }
#else
    #define ASSERT_OK(type, what)
#endif

#define FILEREAD "eugen_onegin.txt"
#define FILEWRITE_NORMAL "eugen_onegin_2.txt"
#define FILEWRITE_SORTED "eugen_onegin_sorted.txt"
#define FILEWRITE_RHYME "eugen_onegin_rhyme.txt"


enum success {OK = 0, OS_FAULT = 2, FILE_ERROR = 3, SEEK_ERROR = 4, POISON = -11};

struct line_t
{
    char* pointer;
    int begining;
    int ending;
};

int readfileD(const char* filename, char* buffer[], int* len);
int StrRevcmp(line_t str1, line_t str2);
int mlStrcmp(line_t str1, line_t str2);
int my_isalpha (char a);
line_t line_ctor (char* pointer, char* ending);
void line_dtor (line_t* This);
int line_t_OK (const line_t* This);
void line_t_dump (const line_t* This);
int make_file(const char* filename, line_t* text, int nline);
line_t* split_linesD(char* buffer, int len, int* nline);
void liborator (line_t* text, char* buffer);
void quicksort (line_t* text, int left, int right, int (*cmp) (line_t str1, line_t str2));
void Swap (line_t* str1, line_t* str2);

int main()
{
    setlocale(LC_ALL, "Russian");
    printf("This is sorting of %s\n", FILEREAD);
    int len = 0;
    char* buffer;
    if (readfileD(FILEREAD, &buffer, &len))
    {
        printf("INPUT ERROR\n");
    }
    int nline = 0;
    line_t* text = split_linesD (buffer, len, &nline);

    if (make_file(FILEWRITE_NORMAL, text, nline))
    {
        printf("OUTPUT ERROR IN %s\n", FILEWRITE_NORMAL);
    }

    quicksort (text, 0, nline - 1, mlStrcmp);
    if (make_file(FILEWRITE_SORTED, text, nline))
    {
        printf("OUTPUT ERROR IN %s\n", FILEWRITE_SORTED);
    }

    quicksort (text, 0, nline - 1, StrRevcmp);
    if (make_file(FILEWRITE_RHYME, text, nline))
    {
        printf("OUTPUT ERROR IN %s\n", FILEWRITE_RHYME);
    }

    liborator(text, buffer);

    printf ("you can find your text in %s\n", FILEWRITE_NORMAL);
    printf ("you can find sorted text in %s\n", FILEWRITE_SORTED);
    printf ("you can find backwards sorted text in %s\n", FILEWRITE_RHYME);

    return OK;
}

/**
@brief чтение файла: считывает файл и сохраняет в единый буфер, заказывая динамическую память

@param filename название исходного файла
@param buffer   буфер для записи
@param len      длина буфера

@return сообщение об ошибках: \
FILE_ERROR = 3 ошибка при чтении файла \
SEEK_ERROR = 4 ошибка при определении длины буфера
*/

int readfileD(const char* filename, char* buffer[], int* len)
{
    assert(buffer);
    assert(len);
    assert(filename);

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


/**
@brief сравнение строк с конца

@param str1 строка для сравнения
@param str2 строка для сравнения

@return целое число >0 если больше первая строка, <0 если больше вторая строка, = 0 в случае равенства
*/

int StrRevcmp(line_t str1, line_t str2)
{
        int i = str1.ending;
        int j = str2.ending;
        while (str1.pointer[i] == str2.pointer[j])
        {
            i--;
            j--;
            if ((i == 0) || (j == 0)) return 0;
        }
        return str1.pointer[i] - str2.pointer[j];
}


 /**
@brief сравнение строк

@param str1 строка для сравнения
@param str2 строка для сравнения

@return целое число >0 если больше первая строка, <0 если больше вторая строка, = 0 в случае равенства
*/

int mlStrcmp(line_t str1, line_t str2)
{
    int i = str1.begining;
    int j = str2.begining;
    while (str1.pointer[i] == str2.pointer[j])
    {
        i++;
        j++;
        if ((str1.pointer[i] == '\0') || (str1.pointer[j] == '\0')) return 0;
    }
        return str1.pointer[i] - str2.pointer[j];
}

int my_isalpha (char a)
{
    if (isalpha(a) || a == 'я') return 1;
    else return 0;
}


/**
@brief конструктор структуры типа line_t

@param pointer указатель на начало строки в буфере
@param ending указатель на конец строки в буфере

@return структура типа line_t
*/

line_t line_ctor (char* pointer, char* ending)
{
    assert (pointer);
    assert (ending);

    line_t This;
    int length = ending - pointer;
    This.pointer = pointer;
    int i = 0;
    for (i = 0 ; my_isalpha(This.pointer[i]) == 0; i++)
            ;
    This.begining = i;
    for (i = length - 1; my_isalpha(This.pointer[i]) == 0; i--)
            ;
    This.ending = i;

    ASSERT_OK(line_t, &This);

    return This;
}

void line_dtor (line_t* This)
{
    ASSERT_OK(line_t, This);
    (*This).pointer   = NULL;
    (*This).begining = POISON;
    (*This).ending   = POISON;
}

int line_t_OK (const line_t* This)
{
    return This && (*This).pointer && ((*This).begining >= 0) && ((*This).ending >= 0);
}

void line_t_dump (const line_t* This)
{
    assert(This);

    printf("line_t(",  line_t_OK (This) ? "OK" : "TROUBLE", ")\n");
    printf("{\n");
    printf("*pointer = %s;\n", (*This).pointer);
    printf("begining = %d;\n", (*This).begining);
    printf("ending   = %d;\n", (*This).ending);
    printf("}");
}


/**
@brief запись в файл

@param filename название исходного файла
@param text массив с указателями на строки
@param nline число строк

@return сообщение об ошибках
FILE_ERROR = 3 ошибка открытия файла для записи
*/

int make_file(const char* filename, line_t* text, int nline)
{
    assert(text);

    FILE* NewText = fopen(filename, "wb");
    if (!NewText)
        return FILE_ERROR;
    for (int i = 0; i < nline; i++)
    {
        assert(0 <= i && i < nline);
        if (text[i].pointer[0] != '\0')
        {
            fprintf (NewText, "%s\n", text[i].pointer);
        }
    }
    fclose(NewText);
    return OK;
}


/**
@brief деление буфера на строки

@param buffer буфер с текстом
@param len длина буфера
@param nline число строк в буфере

@return адрес начала массива со структурами
*/

line_t* split_linesD(char* buffer, int len, int* nline)
{
    assert(nline);
    assert(*nline == 0);
    assert(buffer);

    for (int i = 0; i <= len; i++)
    {
        assert (0 <= i && i <= len);
        if (buffer[i] == '\r')
            {
                (*nline)++;
                buffer[i] = '\0';
            }
    }

    line_t* text = (line_t*)calloc(*nline, sizeof(line_t));
    assert(text);

   char* mem = buffer;
   int j = 0;
   for (int i = 0; i <  len ; i++)
   {
       assert (0 <= i && i  < len);

        if (buffer[i] == '\0')
        {
            char* curlen = &buffer[i + OS_FAULT];
            if ((curlen - buffer) >= len) curlen = &buffer[i];
            text[j] = line_ctor (mem, curlen);
            mem = curlen;
            j++;

            assert (1 <= j && j <= (*nline));
        }
   }
    return text;
}

void liborator (line_t* text, char* buffer)
{
    assert (text);
    assert (buffer);

    free(buffer);
    free(text);
}


/**
@brief быстрая сортировка  строк с помощью выбранного компаратора

@param text массив структур
@param  last - номер последней структуры в массиве
@param first - номер первой структуры в массиве
@param (*cmp) - компаратор

@return void
*/

void quicksort(line_t* text, int first, int last, int (*cmp) (line_t str1, line_t str2))
{
    assert(text);

    int i = first, j = last;
    line_t mid = text[(first + last) / 2];

    do
    {
        while (cmp (text[i], mid) < 0)
            i++;
        while (cmp (text[j], mid) > 0)
            j--;

        if(i <= j)
        {
            if (cmp (text[i], text[j]) > 0)
            {
                Swap (&text[i], &text[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        quicksort(text, i, last, cmp);
    if (first < j)
        quicksort(text, first, j, cmp);
}

void Swap (line_t* str1, line_t* str2)
{
    line_t Buf = *str1;
    *str1 = *str2;
    *str2 = Buf;
}


