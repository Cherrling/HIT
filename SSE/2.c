// ��̴Ӽ�������һ��СдӢ����ĸ������ת��Ϊ��дӢ����ĸ������ת����Ĵ�дӢ����ĸ����ʮ���Ƶ�ASCII��ֵ��ʾ����Ļ�ϡ�
// **������ʾ��Ϣ**��"Please input a low-case letter from keyboard:"
// **�������ݸ�ʽ**��"%c"
// **������ݸ�ʽ**��"The capital letter and its ASCII value are:%c and %d.\n"
// "
// ��ʾ���Ӽ�������һ���ַ�����scanfҲ����getchar
#include<stdio.h>


int main(){
    char ch;
    printf("Please input a low-case letter from keyboard:");
    scanf("%c",&ch);
    printf("The capital letter and its ASCII value are:%c and %d.\n",ch-32,ch-32);
    return 0;
    
}