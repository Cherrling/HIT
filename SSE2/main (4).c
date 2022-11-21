#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 编程计算分段：
//      当x<0时，    y=3x-1；
//   当0<=x<10时，   y=e^x
//      当x>=10时，  y=x；
// 从键盘输入一个单精度实数x，打印出y值。
// **输入提示信息格式要求为："Please input x:\n"；
// **输出格式要求为"y = %.2f\n"。
// <说明>e^x表示e的x次幂，使用数学函数exp(x)表示。

int main()
{
    float x;
    float y;
    printf("Please input x:\n");
    scanf("%f", &x);
    if (x < 0)
    {
        y = 3 * x - 1;
    }
    else if (x < 10)
    {
        y = exp(x);
    }
    else
    {
        y = x;
    }
    printf("y = %.2f\n", y);
}