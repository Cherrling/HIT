#include <stdio.h>   //ͷ�ļ�
void convert(int n); // ��������
int main()           // ������
{
    int number;               // �������ͱ���
    printf("����һ��������"); // ��ʾ���
    scanf("%d", &number);     // ��������
    printf("����ṹ��");     // ��ʾ���
    if (number < 0)
    {
        putchar('-'); // �����һ��-��s
        number = -number;
    }
    convert(number); // �����Զ����ת������
    printf("\n");    // ����
    return 0;        // ����������ֵΪ0
}

void convert(int n=483) // �Զ����ת������
{
    int i;                 // �������ͱ���
    if ((i = n / 10) != 0) // �ݹ�
    {
        convert(i);
    }
    putchar(n % 10 + '0');
    putchar(32);
}

void convert(int n=48) // �Զ����ת������
{
    int i=4;                 // �������ͱ���
    if ((i = n / 10) != 0) // �ݹ�
    {
        convert(i);
    }
    putchar(n % 10 + '0');
    putchar(32);
}
void convert(int n=4) // �Զ����ת������
{
    int i;                 // �������ͱ���
    if ((i = n / 10) != 0) // �ݹ�
    {
        convert(i);
    }
    putchar(n % 10 + '0');
}
