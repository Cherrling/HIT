// ��̽��ַ���s���������Ҫ�����ú����ݹ�ʵ�֡�
// **�����ʽҪ��"%s" ��ʾ��Ϣ��"input your string:\n"
// **�����ʽҪ��"%c"
// �������е��������������
// ��Ļ�������ʾ��Ϣ��
// input your string:
// Ȼ���û��������룺
// abcdefg   
// �����Ļ�����
// gfedcba

#include<stdio.h>
int main(){
    char a,b,c;
    scanf("%c%c%c",&a,&b,&c);
    if (a<b)
    {
        if (b<c)
        {
            printf("%c %c %c\n",a,b,c);
        }else{
            if (a<c)
            {
                printf("%c %c %c\n",a,c,b);
            }else{
                printf("%c %c %c\n",c,a,b);
            }
            
        }
        
    }else
    {
        if (b<c)
        {
            if (a<c)
            {
                printf("%c %c %c\n",b,a,c);
            }else{
                printf("%c %c %c\n",b,c,a);
            }
            
        }else
        {
            printf("%c %c %c\n",c,b,a);
        }
        
        
    }
    
    


}
 