// ������ʾ
// ��дһ������, �����û�¼���������Ϣ���ҽ�����ʾ����. ����, �������ڵ���ʽΪ�� �� ��(yy mm dd), ������ڵ���ʽΪ������(mm/dd/yy)��

// ���������ʾ����
// Enter a date(year month day):
// 2015 3 2�L
// You entered the date: 03/02/2015

// �����ʽ: "%d%d%d"

// �����ʽ��
// ������ʾ��Ϣ�� "Enter a date(year month day):\n"
// �����ʽ�� "You entered the date: %02d/%02d/%d"

#include<stdio.h>

int main(){
    printf("Enter a date(year month day):\n");
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    printf("You entered the date: %02d/%02d/%d",m,d,y);
    return 0;



}