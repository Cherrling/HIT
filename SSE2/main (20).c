#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �Ӽ�����������һ���ַ������������Ǵ�дӢ����ĸ������ת��ΪСдӢ����ĸ��Ȼ�󽫸�СдӢ����ĸ������Ӧ��ASCIIֵ��ӡ���������������СдӢ����ĸ������ת��Ϊ��дӢ����ĸ��Ȼ�󽫸ô�дӢ����ĸ������Ӧ��ASCII��ֵ��ӡ��������������������ַ����򽫸��ַ�ԭ����ӡ�����
// **������ʾ��Ϣ**��"Please enter a char:\n"
// **�������ݸ�ʽ**��"%c"
// **������ݸ�ʽ**��"%c,%d\n" �� "%c"
// ע����д��ĸA��ASCII��ֵ�ǣ�65
//     Сд��ĸa��ASCII��ֵ�ǣ�97



int main(){
    printf("Please enter a char:\n");
    char ch;
    scanf("%c",&ch);
    if (ch>='a'&&ch<='z')
    {
        printf("%c,%d\n",ch-32,ch-32);
    }
      else  if (ch>='A'&&ch<='Z')
    {
        printf("%c,%d\n",ch+32,ch+32);
    }else{
        printf("%c",ch);
    }

}