#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��̼���ֶΣ�
//      y= x               x<1
//      y= 2x-1            1<=x<10
//      y= 3x-11           x>=10
// �Ӽ�������һ��������ʵ��x����ӡ��yֵ��
// **������ʾ��Ϣ��ʽҪ��Ϊ��"Please input x:"��
// **�����ʽҪ��Ϊ"y = %.2f\n"��


int main(){
    printf("Please input x:");
    float x,y;
    scanf("%f",&x);
    if (x<1)
    {
        y=x;
    }else if (x<=10)
    {
        y=2*x-1;
    }else if (x>=10)
    {
        y=3*x-11;
    }
    printf("y = %.2f\n",y);
    
    
    
}