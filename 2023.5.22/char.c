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
// 复制字符串 s2 到字符串 s1。
// 2	strcat(s1, s2);
// 连接字符串 s2 到字符串 s1 的末尾。
// 3	strlen(s1);
// 返回字符串 s1 的长度。
// 4	strcmp(s1, s2);
// 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
// 5	strchr(s1, ch);
// 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
// 6	strstr(s1, s2);
// 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。







int main ()
{
   char str1[] = "runoob";
   char str2[14] = "google";
   char str3[14];
   int  len ;
 
   /* 复制 str1 到 str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );
 
   /* 连接 str1 和 str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );
 
   /* 连接后，str1 的总长度 */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );
 
   return 0;
}