#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// �����������еĽϴ�ֵ��
// **�����ʽҪ��"%d%d"  ��ʾ��Ϣ��"input a and b="
// **�����ʽҪ��"The max of a and b :%d\n"
// ��������ʾ�����£�
// input a and b=5 6
// The max of a and b :6

int main(){
    int a,b;
    printf("input a and b=");
    scanf("%d%d",&a,&b);
    printf("The max of a and b :%d\n",(a>b?a:b));
}