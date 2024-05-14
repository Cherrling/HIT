// 给定如下定义：
struct date_rec
{
    int day;
    int month;
    int year;
};
// 写一个函数接收两个日期，如果两个日期相同，则返回0，如果第一个日期晚于第二个日期，则返回1，如果第一个日期早于第二个日期，则返回-1。并编写main函数测试它。

// **输入格式要求："%d%d%d" 提示信息："请输入当前日期（年 月 日）："
// **输出格式要求："当前日期：%d年%d月%d日！\n" "第一个日期晚于第二个日期！" "第一个日期早于第二个日期！"  "两个日期相同！"

// 程序运行示例如下：

// 请输入当前日期（年 月 日）：2012 9 10
// 请输入当前日期（年 月 日）：2013 7 10
// 当前日期：2012年9月10日！
// 当前日期：2013年7月10日！
// 第一个日期早于第二个日期！
#include <stdio.h>

struct date_rec
{
    int day;
    int month;
    int year;
};

int datecmp(struct date_rec *date1, struct date_rec *date2);

int main()
{
    struct date_rec date1, date2;
    int ret;
    printf("请输入当前日期（年 月 日）：");
    scanf("%d%d%d", &date1.year, &date1.month, &date1.day);
    printf("请输入当前日期（年 月 日）：");
    scanf("%d%d%d", &date2.year, &date2.month, &date2.day);
    ret = datecmp(&date1, &date2);
    printf("当前日期：%d年%d月%d日！\n", date1.year, date1.month, date1.day);
    printf("当前日期：%d年%d月%d日！\n", date2.year, date2.month, date2.day);

    //switch
    if (ret == 0)
    {
        printf("两个日期相同！");
    }
    else if (ret == -1)
    {
        printf("第一个日期早于第二个日期！");
    }
    else
    {
        printf("第一个日期晚于第二个日期！");
    }
    return 0;
}

int datecmp(struct date_rec *date1, struct date_rec *date2)
{
    int yeargap, monthgap, daygap;
    yeargap = (date1->year) - (date2->year);
    monthgap = (date1->month) - (date2->month);
    daygap = (date1->day) - (date2->day);
    if (yeargap > 0)
    {
        return 1;
    }
    else if (yeargap < 0)
    {
        return -1;
    }
    else
    {
        if (monthgap > 0)
            return 1;
        else if (monthgap < 0)
            return -1;
        else
        {
            if (daygap > 0)
                return 1;
            else if (daygap < 0)
                return -1;
            else
                return 0;
        }
    }
}