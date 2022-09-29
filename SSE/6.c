// 求前驱字符和后继字符。输入一个字符，找出它的前驱和后继字符，并按ASCII码值，按从小到大顺序输出这三个字符及其对应的ASCII码值。（注：一个字符的前驱字符是指在ASCII码表中，排列在该字符前面的一个字符，即比该字符的ASCII码值小1的字符。一个字符的后继字符是指在ASCII码表中，排列在该字符后面的一个字符。）
// **输入格式要求："%c"  提示信息："Enter a character:"
// **输出格式要求："%c %c %c\n"   "%d %d %d\n"
// 程序运行示例如下：
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