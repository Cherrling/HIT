// 从键盘输入一个大写英文字母，将其转换为小写英文字母后，将转换后的小写英文字母及其十进制的ASCII码值显示到屏幕上。
// **输入格式要求：提示信息："Press a key and then press Enter:"
// **输出格式要求："%c, %d\n" 
// 程序运行示例如下：
// Press a key and then press Enter:B
// b, 98

#include<stdio.h>

int main(){

    printf("Press a key and then press Enter:");
    char ch;
    scanf("%c",&ch);
    printf("%c, %d\n" ,(ch+32),ch+32);
    
    
}