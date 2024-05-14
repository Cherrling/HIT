#include <stdio.h>
#include <string.h>
#include <ctype.h>
int IsNumIn(char word[]);
int IsSpcIn(char word[]);
void Trim(char oldWord[], char newWord[]);
void Seg(char words[], char wArray[][100]);

int main()
{
    char str[100], a[100], array[10][100]={"-1"};
    gets(str);
    Trim(str, a);

    int i;
    // for (i = 0; a[i] != '\0'; i++)
    // {
        if (IsNumIn(a))
        {
            printf("error");
        }
        else
        {
            if (IsSpcIn(a))
            {
                Seg(a, array);    
                // for (i = 0; i < 100; i++)
                // {
                //     puts(array[i]);
                // }                
                for (i = 0; array[i][0]!='\0'; i++)
                {
                    puts(array[i]);
                }
            }
            else
                puts(a);
        }
    // }
    return 0;
}

int IsNumIn(char word[])
{
    int i;
    for (i = 0; *(word + i) != '\0'; i++)
    {
        if (isdigit(*(word + i)))
            return 1;
    }
    return 0;
}
int IsSpcIn(char word[])
{
    int i;
    for (i = 0; *(word + i) != '\0'; i++)
    {
        if (isspace(*(word + i)))
            return 1;
    }
    return 0;
}
void Trim(char oldWord[], char newWord[])
{
    int i = 0, j = 0;
    while (*(oldWord + i) == ' ')
        i++;
    while (*(oldWord + i) != '\0')
    {
        *(newWord + j) = *(oldWord + i);
        i++;
        j++;
    }
    i--;
    j--;
    for (; *(oldWord + i) == ' '; i--, j--)
    {
        *(newWord + j) = '\0';
    }
}
void Seg(char words[], char wArray[][100])
{
    int i = 0, j = 0, k = 0;
    for (i = 0; words[i] != '\0'; i++)
    {
        if (words[i] >= 'a' && words[i] <= 'z')
        {
            wArray[j][k] = *(words + i);
            k++;
        }
        else
        {
            wArray[j][k] = '\0';
            j++;
            k = 0;
        }
    }
}