#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��������������е����ֵ��
// **�����ʽҪ��"%d%d" ��ʾ��Ϣ��"input the value of x and y:"
// **�����ʽҪ��"The max of %d and %d  is %d\n"
// ����ʾ���������£�
// input the value of x and y:3 4
// The max of 3 and 4 is 4

int main(){
    int a,b;
    printf("input the value of x and y:");
    scanf("%d%d",&a,&b);
    printf("The max of %d and %d  is %d\n",a,b,(a>b?a:b));
}