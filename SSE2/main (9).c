#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �Ӽ�����������һ������������ж�������ż�ԡ�
// **�����ʽҪ��"%d" ��ʾ��Ϣ��"Input an integer number:"
// **�����ʽҪ��"a is an even number\n" "a is an odd number\n"
// ��������ʾ��1���£�
// Input an integer number:2
// a is an even number
// ��������ʾ��2���£�
// Input an integer number:5
// a is an odd number


int main(){
    printf("Input an integer number:");
    int n;
    scanf("%d",&n);
    if (n%2==0)
    {
        printf("a is an even number\n");
    }else{
        printf("a is an odd number\n");

    }
    
}