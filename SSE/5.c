// 从键盘输入一个小写英文字母,将其转换成大写英文字母后,输出大写英文字母及其对应的十进制ASCII码值.
// **输入格式要求：无任何信息提示；
// **输出格式要求："%c,%d\n"

#include<stdio.h>

int main(){
    char ch;
    scanf("%c",&ch);
    printf("%c,%d\n" ,(ch-32),ch-32);

    
}