// 日期显示
// 编写一个程序, 接收用户录入的日期信息并且将其显示出来. 其中, 输入日期的形式为年 月 日(yy mm dd), 输出日期的形式为年月日(mm/dd/yy)。

// 程序的运行示例：
// Enter a date(year month day):
// 2015 3 2↙
// You entered the date: 03/02/2015

// 输入格式: "%d%d%d"

// 输出格式：
// 输入提示信息： "Enter a date(year month day):\n"
// 输出格式： "You entered the date: %02d/%02d/%d"

#include<stdio.h>

int main(){
    printf("Enter a date(year month day):\n");
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    printf("You entered the date: %02d/%02d/%d",m,d,y);
    return 0;



}