#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// �Ӽ�����������һ���ַ�������жϸ��ַ��������ַ���Ӣ����ĸ���ո��������ַ���
// **�����ʽҪ����ʾ��Ϣ��"Press a key and then press Enter:"
// **�����ʽҪ��"It is an English character!\n" "It is a digit character!\n"  "It is a space character!\n"  "It is other character!\n"
// ��������ʾ��1���£�
// Press a key and then press Enter:A
// It is an English character!
// ��������ʾ��2���£�
// Press a key and then press Enter:2
// It is a digit character!
// ��������ʾ��3���£�
// Press a key and then press Enter: 
// It is a space character!
// ��������ʾ��4���£�
// Press a key and then press Enter:#
// It is other character!



int main(){
    printf("Press a key and then press Enter:");
    char ch;
    scanf("%c",&ch);
    if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    {
        printf("It is an English character!\n");
    }else if (ch==' ')
    {
        printf("It is a space character!\n");
    }else if (ch>='0'&&ch<='9')
    {
        printf("It is a digit character!\n");
    }else{
        printf("It is other character!\n");
    }
}