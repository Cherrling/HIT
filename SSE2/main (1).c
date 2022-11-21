#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 写一个程序从键盘输入1到7中的某个数字，其中1代表星期天，2代表星期一，3代表星期二等。根据用户输入的数字显示相应的星期几。如果用户输入的数字超出了1到7的范围，显示输出一个错误提示信息。
// **输入格式要求："%d" 提示信息："Please input a single numeral(1-7): "
// **输出格式要求："Monday\n" （星期几的英文单词首字母大写加换行）
// 提示信息："Invalid - please input a single numeral(1-7).\n"

int main()
{
    printf("Please input a single numeral(1-7): ");
    int n;
    scanf("%d", &n);
    if (n > 7 || n < 1)
    {
        printf("Invalid - please input a single numeral(1-7).\n");
    }
    else
    {
        switch (n)
        {
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        case 7:
            printf("Saturday\n");
            break;
        case 1:
            printf("Sunday\n");
            break;

        default:
            break;
        }
    }
}