#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 使用条件运算符编程，计算并输出两个整数的最大值。
// **输入格式要求："%d,%d" 提示信息："Input a, b:"
// **输出格式要求："max = %d\n"
// 程序运行示例如下：
// Input a, b:3,5
// max = 5


int main(){
    int a,b;
    printf("Input a, b:");
    scanf("%d,%d",&a,&b);
    printf("max = %d\n",(a>b?a:b));

}