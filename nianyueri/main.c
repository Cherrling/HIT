#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>
struct date
{
    int y;
    int m;
    int d;
};

int runnian(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("请输入日期（年，月，日）\n");
    struct date date;
    int num=0;
    scanf("%d,%d,%d", &date.y, &date.m, &date.d);
    for (int i = 1; i < date.m; i++)
    {
        switch (i)
        {
        case 1:
            num += 31;
            break;
        case 2:
            if (runnian(date.y))
            {
                num += 29;
            }
            else
            {
                num += 28;
            }

            break;
        case 3:
            num += 31;
            break;
        case 4:
            num += 30;
            break;
        case 5:
            num += 31;
            break;
        case 6:
            num += 30;
            break;
        case 7:
            num += 31;
            break;
        case 8:
            num += 31;
            break;
        case 9:
            num += 30;
            break;
        case 10:
            num += 31;
            break;
        case 11:
            num += 30;
            break;

        default:
            break;
        }
    }
    num += date.d;
    printf("%d月%d日是%d年的第%d天\n", date.m, date.d, date.y, num);
}