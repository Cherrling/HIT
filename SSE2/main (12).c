#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ���̼������Ӧ��ˮ�ѣ����ṩ���ֲ������ݡ�����Ӧ��ˮ��y��Ԫ��������ˮ��x���֣��ĺ�����ϵʽ���£�

// y=f(x)=�6�1�6�3�6�20,4x3,2.5x�6�110.5,x<00��x��15x>15

// **�����ʽҪ����Ϣ��ʾ��"Enter x:" �����ʽ��"%lf"
// **�����ʽҪ��"f(%.2f)=%.2f\n"


int main(){
    printf("Enter x:");
    double x;
    scanf("%lf",&x);
    double y;
    if (x<0)
    {
        y=0;
    }else if (x>=0&&x<=15)
    {
        y=4*x/3;
    }else if (x>15)
    {
        y=2.5*x-10.5;
    }
    printf("f(%.2f)=%.2f\n",x,y);
    
    
}