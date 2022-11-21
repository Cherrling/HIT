#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 请编程计算居民应交水费，并提供各种测试数据。居民应交水费y（元）与月用水量x（吨）的函数关系式如下：

// y=f(x)=⎧⎩⎨0,4x3,2.5x−10.5,x<00≤x≤15x>15

// **输入格式要求：信息提示："Enter x:" 输入格式："%lf"
// **输出格式要求："f(%.2f)=%.2f\n"


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