#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// �Ӽ�����������һ��ʵ������ʹ�ü������ֵ������̼��㲢�����ʵ���ľ���ֵ��
// **�����ʽҪ��"%f" ��ʾ��Ϣ��"Input a float number:"
// **�����ʽҪ��"Absolute value of x is %f\n"
// ��������ʾ�����£�
// Input a float number:-2.3
// Absolute value of x is 2.300000


int main(){
    printf("Input a float number:");
    float n;
    scanf("%f",&n);
    printf("Absolute value of x is %f\n",(n>0?n:-n));
}