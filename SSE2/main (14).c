#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �Ӽ�������һ��Ӣ����ĸ��������Ǵ�дӢ����ĸ������ת��ΪСдӢ����ĸ���������СдӢ����ĸ������ת��Ϊ��дӢ����ĸ��Ȼ��������ASCII��ֵ��ʾ����Ļ�ϣ��������Ӣ����ĸ����ת��ֱ���������Ļ�ϡ�
// **�����ʽҪ����ʾ��Ϣ��"Press a key and then press Enter:"
// **�����ʽҪ��"%c, %d\n"
// ��������ʾ��1���£�
// Press a key and then press Enter:A
// a, 97
// ��������ʾ��2���£�
// Press a key and then press Enter:a
// A, 65


int main(){
    printf("Press a key and then press Enter:");
    char ch;
    scanf("%c",&ch);
    if (ch>='a'&&ch<='z')
    {
        printf("%c, %d\n",ch-32,ch-32);
    }
      else  if (ch>='A'&&ch<='Z')
    {
        printf("%c, %d\n",ch+32,ch+32);
    }else{
        printf("%c",ch);
    }
}