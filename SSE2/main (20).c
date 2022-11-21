#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 从键盘输入任意一个字符。如果输入的是大写英文字母，则将其转换为小写英文字母，然后将该小写英文字母及所对应的ASCII值打印输出；如果输入的是小写英文字母，则将其转换为大写英文字母，然后将该大写英文字母及所对应的ASCII码值打印输出；如果输入的是其它字符，则将该字符原样打印输出。
// **输入提示信息**："Please enter a char:\n"
// **输入数据格式**："%c"
// **输出数据格式**："%c,%d\n" 或 "%c"
// 注：大写字母A的ASCII码值是：65
//     小写字母a的ASCII码值是：97



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