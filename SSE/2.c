// 编程从键盘输入一个小写英文字母，将其转换为大写英文字母，并将转换后的大写英文字母及其十进制的ASCII码值显示到屏幕上。
// **输入提示信息**："Please input a low-case letter from keyboard:"
// **输入数据格式**："%c"
// **输出数据格式**："The capital letter and its ASCII value are:%c and %d.\n"
// "
// 提示：从键盘输入一个字符可用scanf也可用getchar
#include<stdio.h>


int main(){
    char ch;
    printf("Please input a low-case letter from keyboard:");
    scanf("%c",&ch);
    printf("The capital letter and its ASCII value are:%c and %d.\n",ch-32,ch-32);
    return 0;
    
}