#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 从键盘输入一个英文字母，如果它是大写英文字母，则将其转换为小写英文字母，如果它是小写英文字母，则将其转换为大写英文字母，然后将它及其ASCII码值显示到屏幕上，如果不是英文字母，则不转换直接输出到屏幕上。
// **输入格式要求：提示信息："Press a key and then press Enter:"
// **输出格式要求："%c, %d\n"
// 程序运行示例1如下：
// Press a key and then press Enter:A
// a, 97
// 程序运行示例2如下：
// Press a key and then press Enter:a
// A, 65


int main(){
    printf("Press a key and then press Enter:");
    char ch;
    scanf("%c",&ch);
    if (ch>='a'&&ch<='z')
    {
        printf("%c, %d\n",ch-32,ch-32);
    }
      else  if (ch>='A'&&ch<='Z')
    {
        printf("%c, %d\n",ch+32,ch+32);
    }else{
        printf("%c",ch);
    }
}