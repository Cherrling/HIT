#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<math.h>

// ��д����ʵ�����¹��ܣ��Ӽ�����������������a��b��c����a��b��c��ֵ�ܹ��������Σ�����㲢��������ε�����������ӡ������������Ρ���֪��������������Ĺ�ʽΪ��
//      s=(a+b+c)/2
//     area=sqrt(s(s-a)(s-b)(s-c))
// ***������ʾ��Ϣ��"Input a,b,c:"
// ***�������ݸ�ʽ��"%f,%f,%f"
// ***�����ʽҪ��
//     ���������Σ���������ݸ�ʽΪ��"area=%.4f\n"
//   �����������Σ���������ݸ�ʽΪ��"It is not a triangle\n"

int main()
{
    float a,b,c,s,area;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    if (a+b>c&&a+c>b&&b+c>a)
    {
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        printf("area=%.4f\n",area);
    }
    else
    {
        printf("It is not a triangle\n");
    }
    return 0;
    
}