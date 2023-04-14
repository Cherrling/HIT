// �������Լ��������3�����ʣ���д�������Լ���ĺ���Gcd()�����������е��øú������㲢����Ӽ�������������������������Լ����
// ����1  ���a>b����a��b��a-b��b�����Լ����ͬ����Gcd(a, b) = Gcd(a-b, b)
// ����2  ���b>a����a��b��a��b-a�����Լ����ͬ����Gcd(a, b) = Gcd(a, b-a)
// ����3  ���a=b����a��b�����Լ����aֵ��bֵ��ͬ����Gcd(a, b) = a = b
// Ҫ�����£�
// ��1���Ӽ������������������
//      ����������Gcd()����������������������Լ����
// ��2��Gcd����ԭ��Ϊ��
//      int Gcd(int a, int b);
//      �����������������������򷵻�-1�����򣬷��������������Լ����
// ��3��**������ʾ��Ϣ��ʽҪ��"Input a,b:"
//        �����ʽ��"%d,%d"
//      **�����ʾ��ϢҪ��
//        �����벻���������������"Input number should be positive!\n"
//        �������"Greatest Common Divisor of %d and %d is %d\n"
// ע��������ʹ��goto���


#include <stdio.h>
int Gcd(int a, int b);
int main()
{
    int a, b, c;

    printf("Input a,b:");
    scanf("%d,%d", &a, &b);
    c = Gcd(a, b);
    if (c == -1)
    {
        printf("Input number should be positive!\n");
    }
    else
    {
        printf("Greatest Common Divisor of %d and %d is %d\n", a, b, c);
    }
}

int Gcd(int a, int b)
{
    int r;
    r = a % b;
    if (a <= 0 || b <= 0)
    {
        return -1;
    }
    do
    {
        if (a<b)
        {
            int t;
            t=a;
            a=b;
            b=t;
        }
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    return a;
}
