#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 从键盘任意输入一个字符，编程判断该字符是数字字符、英文字母、空格还是其他字符。
// **输入格式要求：提示信息："Press a key and then press Enter:"
// **输出格式要求："It is an English character!\n" "It is a digit character!\n"  "It is a space character!\n"  "It is other character!\n"
// 程序运行示例1如下：
// Press a key and then press Enter:A
// It is an English character!
// 程序运行示例2如下：
// Press a key and then press Enter:2
// It is a digit character!
// 程序运行示例3如下：
// Press a key and then press Enter: 
// It is a space character!
// 程序运行示例4如下：
// Press a key and then press Enter:#
// It is other character!



int main(){
    printf("Press a key and then press Enter:");
    char ch;
    scanf("%c",&ch);
    if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        printf("It is an English character!\n");
    }else if (ch==' ')
    {
        printf("It is a space character!\n");
    }else if (ch>='0'&&ch<='9')
    {
        printf("It is a digit character!\n");
    }else{
        printf("It is other character!\n");
    }
}