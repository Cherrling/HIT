#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��if-else����̸�������İٷ��Ƴɼ�score��ת������Ӧ������Ƴɼ�grade���������֪ת����׼Ϊ��

// 0-59    E

// 60-69   D

// 70-79   C

// 80-89   B

// 90-100  A

// **�����ʽҪ��"%d" ��ʾ��Ϣ��"Please enter score:"
// **�����ʽҪ��"Input error!\n" "%d����A\n"
// ��������ʾ��1���£�
// Please enter score:15
// 15����E
// ��������ʾ��2���£�
// Please enter score:85
// 85����B

int main()
{
    printf("Please enter score:");
    int n;
    scanf("%d", &n);
    if (n >= 0 && n <= 59)
    {
        printf("%d����E\n", n);
    }
    else if (n >= 60 && n <= 69)
    {
        printf("%d����D\n", n);
    }
    else if (n >= 70 && n <= 79)
    {
        printf("%d����C\n", n);
    }
    else if (n >= 80 && n <= 89)
    {
        printf("%d����B\n", n);
    }
    else if (n >= 90 && n <= 100)
    {
        printf("%d����A\n", n);
    }else{
        printf("Input error!\n");
    }
}