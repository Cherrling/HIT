#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 从键盘任意输入一个实数，不使用计算绝对值函数编程计算并输出该实数的绝对值。
// **输入格式要求："%f" 提示信息："Input a float number:"
// **输出格式要求："Absolute value of x is %f\n"
// 程序运行示例如下：
// Input a float number:-2.3
// Absolute value of x is 2.300000


int main(){
    printf("Input a float number:");
    float n;
    scanf("%f",&n);
    printf("Absolute value of x is %f\n",(n>0?n:-n));
}