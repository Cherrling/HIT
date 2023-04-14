// 写一个程序显示5小时内的所有的小时和分钟值，即：0:00  0:01  0:02 … 4:59。
// **输出格式要求："%d:", "%d\t", "0%d\t"

#include<stdio.h>
int main()
{
    int hour, min;
    for(hour = 0; hour <= 4; hour++)
    {
        for(min = 0; min <= 59; min++)
        {
            printf("%d:", hour);
            if(min <= 9)
            {
                printf("0%d\t", min);
            }
            else
            {
                printf("%d\t", min);
            }
        }
    }
    return 0;
}