#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 从键盘任意输入一个整数，编程判断它的奇偶性。
// **输入格式要求："%d" 提示信息："Input an integer number:"
// **输出格式要求："a is an even number\n" "a is an odd number\n"
// 程序运行示例1如下：
// Input an integer number:2
// a is an even number
// 程序运行示例2如下：
// Input an integer number:5
// a is an odd number


int main(){
    printf("Input an integer number:");
    int n;
    scanf("%d",&n);
    if (n%2==0)
    {
        printf("a is an even number\n");
    }else{
        printf("a is an odd number\n");

    }
    
}