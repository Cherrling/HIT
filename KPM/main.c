// #include <stdio.h>
// #include <string.h>

// #define ARR_SIZE  80

// main()
// {
//     char str[ARR_SIZE];
//     int  len, i;
//     int  letter=0,digit=0,space=0,other=0;

//     printf("请输入一个字符串:");
//     gets(str);

//     len = strlen(str);

//     for (i=0; i<len; i++)
//     {
//         if ('a'<=str[i]&&str[i]<='z' || 'A'<=str[i]&&str[i]<='Z')
//         {
//             letter ++;
//         }
//         else if ('0'<=str[i]&&str[i]<='9')
//         {
//             digit ++;
//         }
//         else if (str[i]==' ')
//         {
//             space ++;
//         }
//         else
//             other ++;
//     }

//     printf("英文字符数:%d\n", letter);
//     printf("数字字符数:%d\n", digit);
//     printf("空格数:%d\n", space);
//     printf("其他字符数:%d\n", other);
// }

// #include<stdio.h>
// #include<string.h>

// void Squeeze(char *s,char c){
// 	printf("Results:");
// 	for (int i = 0; i < strlen(s); i++)
// 	{
// 		if (s[i]!=c)
// 		{
// 			printf("%c",s[i]);
// 		}

// 	}
// 	printf("\n");

// }

// int main(){
// 	char str[80];
// 	char ch;

// 	printf("Input a string:\n");
// 	gets(str);
// 	printf("Input a character:\n");
// 	ch=getchar();
// 	Squeeze(str,ch);

// }

// #include<stdio.h>
// #include<string.h>
// int main(){
//     char str[80];
//     printf("Input a string:\n");
//     gets(str);
//     int t=(str[0]==' '?0:-1);
//     int num=0;
//     for (int i = 0; i <= strlen(str); i++)
//     {
//         if (str[i]==' '||str[i]=='\0')
//         {
//             if (i-t>=4)
//             {
//                 num++;
//             }

//             t=i;

//         }

//     }
//     printf("Numbers of words (include 3 or more letters) = %d\n",num);

// }

#include <stdio.h>
#include <string.h>
#include <math.h>
#define R 10005

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}
int main()
{
    int time = 0;
    char a[1000][R];
    char b[1000][R];
    int a_len, b_len;
    for (int i = 0; i < R; i++)
    {
        gets(a[i]);
        if (!strcmp(a[i], "EOF"))
        {
            a_len = i;
            break;
        }
    }
    for (int i = 0; i < R; i++)
    {
        gets(b[i]);
        if (!strcmp(b[i], "EOF"))
        {
            b_len = i;
            break;
        }
    }
    scanf("%d", &time);

    int back;
    char tmp[R];
    int k;
    for (int i = 0; i < a_len; i++)
    {
        back = 0;
        for (int j = 0; j < strlen(a[i]); j++)
        {
            if (a[i][j] == '<')
            {
                back = 1;
                break;
            }
        }
        if (back)
        {
            for (int p = 0; p < R; p++)
            {
                tmp[p] = '\0';
            }

            k = 0;
            for (int j = 0; j < strlen(a[i]);)
            {
                if (a[i][j] == '<')
                {
                    j++;
                    k--;
                    if (k < 0)
                    {
                        k = 0;
                    }
                }else
                {
                tmp[k] = a[i][j];
                k++;
                j++;
                }
            }
            for (int l = 0; l < strlen(a[i]); l++)
            {
                a[i][l] = '\0';
            }

            strcpy(a[i], tmp);
        }
    }
    for (int i = 0; i < b_len; i++)
    {
        back = 0;
        for (int j = 0; j < strlen(b[i]); j++)
        {
            if (b[i][j] == '<')
            {
                back = 1;
                break;
            }
        }
        if (back)
        {
            for (int p = 0; p < R; p++)
            {
                tmp[p] = '\0';
            }
            k = 0;
            for (int j = 0; j < strlen(b[i]);)
            {
                if (b[i][j] == '<')
                {
                    j++;
                    k--;
                    if (k < 0)
                    {
                        k = 0;
                    }
                }else
                {
                tmp[k] = b[i][j];
                k++;
                j++;
                }
            }
            for (int l = 0; l < strlen(b[i]); l++)
            {
                b[i][l] = '\0';
            }
            strcpy(b[i], tmp);
        }
    }

    int num = 0;
    for (int i = 0; i < min(a_len, b_len); i++)
    {
        for (int j = 0; j < min(strlen(a[i]), strlen(b[i])); j++)
        {
            if (a[i][j] == b[i][j])
            {
                num++;
            }
        }
    }

    printf("%d", (int)((float)(60 * num / time) + 0.5));
}