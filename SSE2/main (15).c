#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 从键盘任意输入一个年号，判断它是否是闰年。若是闰年，则输出"Yes"，否则输出"No"。已知符合下列条件之一者是闰年：1）能被4整除，但不能被100整除；或  2）能被400整除。
// **提示信息格式**: "Input year:\n"
// **输入数据格式**: "%d"
// **输出数据格式**:
//           如果是闰年输出: "Yes"
//           否  则  输  出: "No"

int main()
{

    printf("Input year:\n");
    int year;
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}