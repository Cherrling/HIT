#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ʹ�������������̣����㲢����������������ֵ��
// **�����ʽҪ��"%d,%d" ��ʾ��Ϣ��"Input a, b:"
// **�����ʽҪ��"max = %d\n"
// ��������ʾ�����£�
// Input a, b:3,5
// max = 5


int main(){
    int a,b;
    printf("Input a, b:");
    scanf("%d,%d",&a,&b);
    printf("max = %d\n",(a>b?a:b));

}