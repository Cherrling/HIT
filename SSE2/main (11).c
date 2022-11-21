#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 用if-else语句编程根据输入的百分制成绩score，转换成相应的五分制成绩grade后输出。已知转换标准为：

// 0-59    E

// 60-69   D

// 70-79   C

// 80-89   B

// 90-100  A

// **输入格式要求："%d" 提示信息："Please enter score:"
// **输出格式要求："Input error!\n" "%d——A\n"
// 程序运行示例1如下：
// Please enter score:15
// 15——E
// 程序运行示例2如下：
// Please enter score:85
// 85——B

int main()
{
    printf("Please enter score:");
    int n;
    scanf("%d", &n);
    if (n >= 0 && n <= 59)
    {
        printf("%d——E\n", n);
    }
    else if (n >= 60 && n <= 69)
    {
        printf("%d——D\n", n);
    }
    else if (n >= 70 && n <= 79)
    {
        printf("%d——C\n", n);
    }
    else if (n >= 80 && n <= 89)
    {
        printf("%d——B\n", n);
    }
    else if (n >= 90 && n <= 100)
    {
        printf("%d——A\n", n);
    }else{
        printf("Input error!\n");
    }
}