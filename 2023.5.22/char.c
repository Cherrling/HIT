#include <stdio.h>
#include <string.h>
 


// int main(){

//     char ch[100]="char";
    
//     char *ch1="solid-char";

//     char ch2[100]="char2";
//     char *ptr=ch2;


//     printf("%s\n",ch);
//     printf("%s\n",ch1);
//     printf("%s\n",ptr);
//     printf("---------\n");
//     ch[0]='a';
//     printf("%s\n",ch1);
//     ptr[0]='a';
//     printf("%s\n",ptr);

// }










// 1	strcpy(s1, s2);
// �����ַ��� s2 ���ַ��� s1��
// 2	strcat(s1, s2);
// �����ַ��� s2 ���ַ��� s1 ��ĩβ��
// 3	strlen(s1);
// �����ַ��� s1 �ĳ��ȡ�
// 4	strcmp(s1, s2);
// ��� s1 �� s2 ����ͬ�ģ��򷵻� 0����� s1<s2 �򷵻�С�� 0����� s1>s2 �򷵻ش��� 0��
// 5	strchr(s1, ch);
// ����һ��ָ�룬ָ���ַ��� s1 ���ַ� ch �ĵ�һ�γ��ֵ�λ�á�
// 6	strstr(s1, s2);
// ����һ��ָ�룬ָ���ַ��� s1 ���ַ��� s2 �ĵ�һ�γ��ֵ�λ�á�







int main ()
{
   char str1[] = "runoob";
   char str2[14] = "google";
   char str3[14];
   int  len ;
 
   /* ���� str1 �� str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );
 
   /* ���� str1 �� str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );
 
   /* ���Ӻ�str1 ���ܳ��� */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );
 
   return 0;
}