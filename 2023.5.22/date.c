// �������¶��壺
struct date_rec
{
    int day;
    int month;
    int year;
};
// дһ�����������������ڣ��������������ͬ���򷵻�0�������һ���������ڵڶ������ڣ��򷵻�1�������һ���������ڵڶ������ڣ��򷵻�-1������дmain������������

// **�����ʽҪ��"%d%d%d" ��ʾ��Ϣ��"�����뵱ǰ���ڣ��� �� �գ���"
// **�����ʽҪ��"��ǰ���ڣ�%d��%d��%d�գ�\n" "��һ���������ڵڶ������ڣ�" "��һ���������ڵڶ������ڣ�"  "����������ͬ��"

// ��������ʾ�����£�

// �����뵱ǰ���ڣ��� �� �գ���2012 9 10
// �����뵱ǰ���ڣ��� �� �գ���2013 7 10
// ��ǰ���ڣ�2012��9��10�գ�
// ��ǰ���ڣ�2013��7��10�գ�
// ��һ���������ڵڶ������ڣ�
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
    printf("�����뵱ǰ���ڣ��� �� �գ���");
    scanf("%d%d%d", &date1.year, &date1.month, &date1.day);
    printf("�����뵱ǰ���ڣ��� �� �գ���");
    scanf("%d%d%d", &date2.year, &date2.month, &date2.day);
    ret = datecmp(&date1, &date2);
    printf("��ǰ���ڣ�%d��%d��%d�գ�\n", date1.year, date1.month, date1.day);
    printf("��ǰ���ڣ�%d��%d��%d�գ�\n", date2.year, date2.month, date2.day);

    //switch
    if (ret == 0)
    {
        printf("����������ͬ��");
    }
    else if (ret == -1)
    {
        printf("��һ���������ڵڶ������ڣ�");
    }
    else
    {
        printf("��һ���������ڵڶ������ڣ�");
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