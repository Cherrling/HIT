#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// �Ӽ�����������һ����ţ��ж����Ƿ������ꡣ�������꣬�����"Yes"���������"No"����֪������������֮һ�������꣺1���ܱ�4�����������ܱ�100��������  2���ܱ�400������
// **��ʾ��Ϣ��ʽ**: "Input year:\n"
// **�������ݸ�ʽ**: "%d"
// **������ݸ�ʽ**:
//           ������������: "Yes"
//           ��  ��  ��  ��: "No"

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