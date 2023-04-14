// 从键盘中读入一系列字符，原样输出到屏幕上，直到输入字母a时才停止。
// 程序运行示例1如下：
// dbca   （输入）
// dbc    （输出）
// 程序运行示例2如下：
// first  （输入）
// first  （输出）
// second （输入）
// second （输出）
// a      （输入）
#include <stdio.h>
int main()
{
    char c;
    while((c = getchar())!= 'a')
        printf("%c", c);
    
    return 0;
}