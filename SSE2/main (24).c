#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// 编程判断输入整数的正负性和奇偶性。
// **输入格式要求："%d" 提示信息："Input m:"
// **输出格式要求：
// 如果是负偶数，则输出"%d is a negative even\n" 
// 如果是负奇数，则输出"%d is a negative odd\n"
// 如果是正偶数，则输出"%d is a positive even\n"
// 如果是正奇数，则输出"%d is a positive odd\n"
// 如果是0，则输出"%d is zero. It is an even\n"
// 程序运行示例1：
// Input m:6↙
// 6 is a positive even
// 程序运行示例2：
// Input m:0↙
// 0 is zero. It is an even

int main(){
    int n;
    printf("Input m:");
    scanf("%d",&n);
    if (n==0)
    {
        printf("%d is zero. It is an even\n",n);
    }else if (n>0)
    {
        if (n%2==0)
        {
            printf("%d is a positive even\n",n);
        }else
        {
            printf("%d is a positive odd\n",n);
        }
        
        
    }else
    {
                if (n%2==0)
        {
            printf("%d is a negative even\n",n);
        }else
        {
            printf("%d is a negative odd\n",n);
        }
        
    }
    
    
    
}