#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ж���������x�������Ժ���ż�ԡ�
// **�����ʽҪ��"%d"  ��ʾ��Ϣ��"Enter a integer:"
// **�����ʽҪ��"The integer is a plus even number\n"  "This integer is a plus odd number\n"
//  "This integer is a minus even number\n"    "This integer is a minus odd number\n"
//  "This integer is zero.\n"
// ��������ʾ�����£�
// Enter a integer:-9
// This integer is a minus odd number

int main()
{
    printf("Enter a integer:");
    int n;
    scanf("%d", &n);
    if (n == 0)
    {
        printf("This integer is zero.\n");
    }
    else if (n > 0)
    {
        if (n % 2 == 0)
        {
            printf("The integer is a plus even number\n");
        }
        else
        {
            printf("This integer is a plus odd number\n");
        }
    }
    else
    {
        if (n % 2 == 0)
        {
            printf("This integer is a minus even number\n");
        }
        else
        {
            printf("This integer is a minus odd number\n");
        }
    }
}