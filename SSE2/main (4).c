#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ��̼���ֶΣ�
//      ��x<0ʱ��    y=3x-1��
//   ��0<=x<10ʱ��   y=e^x
//      ��x>=10ʱ��  y=x��
// �Ӽ�������һ��������ʵ��x����ӡ��yֵ��
// **������ʾ��Ϣ��ʽҪ��Ϊ��"Please input x:\n"��
// **�����ʽҪ��Ϊ"y = %.2f\n"��
// <˵��>e^x��ʾe��x���ݣ�ʹ����ѧ����exp(x)��ʾ��

int main()
{
    float x;
    float y;
    printf("Please input x:\n");
    scanf("%f", &x);
    if (x < 0)
    {
        y = 3 * x - 1;
    }
    else if (x < 10)
    {
        y = exp(x);
    }
    else
    {
        y = x;
    }
    printf("y = %.2f\n", y);
}