// дһ��������ʾ5Сʱ�ڵ����е�Сʱ�ͷ���ֵ������0:00  0:01  0:02 �� 4:59��
// **�����ʽҪ��"%d:", "%d\t", "0%d\t"

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