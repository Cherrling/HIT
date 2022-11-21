#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 从键盘任意输入一个整数，编程判断它的奇偶性。要求输入变量定义为int类型且由用户从键盘输入。

// 程序的运行示例1：
// Input an integer number:
// 4↙
// 4 is an even number

// 程序的运行示例2：
// Input an integer number:
// 3↙
// 3 is an odd number

// 输入格式:
// "%d"

// 输出格式：
// 输入信息提示："Input an integer number:\n"
// 偶数输出格式："%d is an even number\n"
// 奇数输出格式："%d is an odd number\n"

int main(){
    printf("Input an integer number:\n");
    int n;
    scanf("%d",&n);
    if (n%2==0)
    {
        printf("%d is an even number\n",n);
    }else{
        printf("%d is an odd number\n",n);
    }
    
}