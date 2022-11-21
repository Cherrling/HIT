#include <stdio.h>
#include <string.h>
#include <math.h>
#define R 100
int Input(char s[1000][R])
{
    char a[R];
    int i = 0;
    while (1)
    {
        gets(a);
        if (a[0] == 'E' && a[1] == 'O' && a[2] == 'F')
            break;
        for (int j = 0; j < strlen(a); j++)
        {
            int k = 0;

            if (a[j] == '<' && j != 0)
            {
                for (k = j; k < strlen(a) - 1; k++)
                {
                    a[k - 1] = a[k + 1];
                }
                a[k] = '\0';
                a[k + 1] = '\0';
            }
            else if (a[j] == '<' && j == 0)
            {
                for (k = 0; k < strlen(a) - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                a[k] = '\0';
                a[k + 1] = '\0';
            }
        }

        strcpy(s[i], a);
        i++;
    }
    return i;
}
int Compare(char s[1000][R], char n[1000][R], int count)
{
    int correct = 0;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (s[i][j] == n[i][j] && s[i][j] != '\0')
            {
                correct++;
            }
        }
    }
    // printf("%d",correct);
    return correct;
}
// void Show(char s[1000][R], int count)
// {
//     for (int i = 0; i < count; i++)
//     {
//         printf("%s\n", s[i]);
//     }
// }

int main()
{
    char s[1000][R];
    char n[1000][R];
    int count;
    int correct = 0;
    int t = 0;
    float KPM = 0;
    count = Input(s);
    // Show(s, count);
    Input(n);
    // Show(n,count);
    scanf("%d", &t);

    correct = Compare(s, n, count);
    KPM = (correct * 1.0 / t * 1.0) * 60;
    KPM = round(KPM);
    printf("%d", (int)KPM);
    return 0;
}
