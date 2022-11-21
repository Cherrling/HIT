#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 编程计算分段：
//      y= x               x<1
//      y= 2x-1            1<=x<10
//      y= 3x-11           x>=10
// 从键盘输入一个单精度实数x，打印出y值。
// **输入提示信息格式要求为："Please input x:"；
// **输出格式要求为"y = %.2f\n"。


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