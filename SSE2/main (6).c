#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 求两个整数中的较大值。
// **输入格式要求："%d%d"  提示信息："input a and b="
// **输出格式要求："The max of a and b :%d\n"
// 程序运行示例如下：
// input a and b=5 6
// The max of a and b :6

int main(){
    int a,b;
    printf("input a and b=");
    scanf("%d%d",&a,&b);
    printf("The max of a and b :%d\n",(a>b?a:b));
}