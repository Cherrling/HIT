#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 编写程序实现如下函数：



// 输入提示信息："input x:\n" 输入格式："%f" 输出格式："y=%.3f" 程序运行示例1： input x: 0↙ y=6.000 程序运行示例2： input x: 21↙ y=39.000

int main(){
    printf("input x:\n");
    float n,y;
    scanf("%f",&n);
    if (n>=-7&&n<=10)
    {
        y=5*n*n-4*n+6;
    }else
    {
        y=n/3+32;
    }
    printf("y=%.3f",y);
    
}