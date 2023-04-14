// 根据最大公约数的如下3条性质，编写计算最大公约数的函数Gcd()，在主函数中调用该函数计算并输出从键盘任意输入的两正整数的最大公约数。
// 性质1  如果a>b，则a和b与a-b和b的最大公约数相同，即Gcd(a, b) = Gcd(a-b, b)
// 性质2  如果b>a，则a和b与a和b-a的最大公约数相同，即Gcd(a, b) = Gcd(a, b-a)
// 性质3  如果a=b，则a和b的最大公约数与a值和b值相同，即Gcd(a, b) = a = b
// 要求如下：
// （1）从键盘任意输入的两整数
//      主函数调用Gcd()函数，并输出两整数的最大公约数。
// （2）Gcd函数原型为：
//      int Gcd(int a, int b);
//      如果输入的数不是正整数，则返回-1，否则，返回两个数的最大公约数。
// （3）**输入提示信息格式要求："Input a,b:"
//        输入格式："%d,%d"
//      **输出提示信息要求：
//        若输入不是正整数，则输出"Input number should be positive!\n"
//        否则输出"Greatest Common Divisor of %d and %d is %d\n"
// 注：不允许使用goto语句


#include <stdio.h>
int Gcd(int a, int b);
int main()
{
    int a, b, c;

    printf("Input a,b:");
    scanf("%d,%d", &a, &b);
    c = Gcd(a, b);
    if (c == -1)
    {
        printf("Input number should be positive!\n");
    }
    else
    {
        printf("Greatest Common Divisor of %d and %d is %d\n", a, b, c);
    }
}

int Gcd(int a, int b)
{
    int r;
    r = a % b;
    if (a <= 0 || b <= 0)
    {
        return -1;
    }
    do
    {
        if (a<b)
        {
            int t;
            t=a;
            a=b;
            b=t;
        }
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    return a;
}
