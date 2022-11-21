#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 输入年份，判断该年是否为闰年。
// **输入格式要求："%d" 提示信息："输入年份:"
// **输出格式要求："%d是闰年!\n" "%d不是闰年!\n"
// 程序示例运行1如下：
// 输入年份: 2012
// 2012是闰年!
// 程序示例运行2如下：
// 输入年份: 2011
// 2011不是闰年!

int main()
{
    printf("输入年份:");
    int year;
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("%d是闰年!\n", year);
    }
    else
    {
        printf("%d不是闰年!\n", year);
    }
}