// �Ӽ�������һ����дӢ����ĸ������ת��ΪСдӢ����ĸ�󣬽�ת�����СдӢ����ĸ����ʮ���Ƶ�ASCII��ֵ��ʾ����Ļ�ϡ�
// **�����ʽҪ����ʾ��Ϣ��"Press a key and then press Enter:"
// **�����ʽҪ��"%c, %d\n" 
// ��������ʾ�����£�
// Press a key and then press Enter:B
// b, 98

#include<stdio.h>

int main(){

    printf("Press a key and then press Enter:");
    char ch;
    scanf("%c",&ch);
    printf("%c, %d\n" ,(ch+32),ch+32);
    
    
}