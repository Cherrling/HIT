#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ���������������ľ���ֵ��
// **�����ʽҪ��"%d" ��ʾ��Ϣ��"input the value of x:"
// **�����ʽҪ��"|x|=%d\n"
// ��������ʾ�����£�
// input the value of x:68
// |x|=68


int main(){
    int n;
    printf("input the value of x:");
    scanf("%d",&n);
    printf("|x|=%d\n",(n>=0?n:-n));
}