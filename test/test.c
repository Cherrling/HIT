// 编程将字符串s倒序输出，要求利用函数递归实现。
// **输入格式要求："%s" 提示信息："input your string:\n"
// **输出格式要求："%c"
// 程序运行的输入输出样例：
// 屏幕先输出提示信息：
// input your string:
// 然后用户键盘输入：
// abcdefg   
// 最后屏幕输出：
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
 