#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// ����ж����������������Ժ���ż�ԡ�
// **�����ʽҪ��"%d" ��ʾ��Ϣ��"Input m:"
// **�����ʽҪ��
// ����Ǹ�ż���������"%d is a negative even\n" 
// ����Ǹ������������"%d is a negative odd\n"
// �������ż���������"%d is a positive even\n"
// ������������������"%d is a positive odd\n"
// �����0�������"%d is zero. It is an even\n"
// ��������ʾ��1��
// Input m:6�L
// 6 is a positive even
// ��������ʾ��2��
// Input m:0�L
// 0 is zero. It is an even

int main(){
    int n;
    printf("Input m:");
    scanf("%d",&n);
    if (n==0)
    {
        printf("%d is zero. It is an even\n",n);
    }else if (n>0)
    {
        if (n%2==0)
        {
            printf("%d is a positive even\n",n);
        }else
        {
            printf("%d is a positive odd\n",n);
        }
        
        
    }else
    {
                if (n%2==0)
        {
            printf("%d is a negative even\n",n);
        }else
        {
            printf("%d is a negative odd\n",n);
        }
        
    }
    
    
    
}