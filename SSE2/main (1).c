#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// дһ������Ӽ�������1��7�е�ĳ�����֣�����1���������죬2��������һ��3�������ڶ��ȡ������û������������ʾ��Ӧ�����ڼ�������û���������ֳ�����1��7�ķ�Χ����ʾ���һ��������ʾ��Ϣ��
// **�����ʽҪ��"%d" ��ʾ��Ϣ��"Please input a single numeral(1-7): "
// **�����ʽҪ��"Monday\n" �����ڼ���Ӣ�ĵ�������ĸ��д�ӻ��У�
// ��ʾ��Ϣ��"Invalid - please input a single numeral(1-7).\n"

int main()
{
    printf("Please input a single numeral(1-7): ");
    int n;
    scanf("%d", &n);
    if (n > 7 || n < 1)
    {
        printf("Invalid - please input a single numeral(1-7).\n");
    }
    else
    {
        switch (n)
        {
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        case 7:
            printf("Saturday\n");
            break;
        case 1:
            printf("Sunday\n");
            break;

        default:
            break;
        }
    }
}