// ��ǰ���ַ��ͺ���ַ�������һ���ַ����ҳ�����ǰ���ͺ���ַ�������ASCII��ֵ������С����˳������������ַ������Ӧ��ASCII��ֵ����ע��һ���ַ���ǰ���ַ���ָ��ASCII����У������ڸ��ַ�ǰ���һ���ַ������ȸ��ַ���ASCII��ֵС1���ַ���һ���ַ��ĺ���ַ���ָ��ASCII����У������ڸ��ַ������һ���ַ�����
// **�����ʽҪ��"%c"  ��ʾ��Ϣ��"Enter a character:"
// **�����ʽҪ��"%c %c %c\n"   "%d %d %d\n"
// ��������ʾ�����£�
// Enter a character:G
// F G H
// 70 71 72

#include<stdio.h>

int main(){
    char ch;
    printf("Enter a character:");
    scanf("%c",&ch);
    printf("%c %c %c\n",ch-1,ch,ch+1);
    printf("%d %d %d\n",ch-1,ch,ch+1);
    return 0;

}