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
    int a,b,c;
    printf("input a and b=");
    scanf("%d%d%d",&a,&b,&c);

    if (a>b)
    {
        if (a>c)
        {
            printf("%d",a);
        }
        else
        {
            printf("%d",c);
        }
    }
    else
    {
        if (b>c)
        {
            printf("%d",b);
        }
        else
        {
            printf("%d",c);
        }
        
        
    }
    
    


    printf("The max of a and b :%d\n",(a>b?a:b));
}