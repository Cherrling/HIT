// �õݹ鷽����̼������Fibonacci���У�ͬʱ��ӡ������Fibonacci����ÿһ��ʱ����ĵݹ���ô�����
// **�����ʽҪ��"%d" ��ʾ��Ϣ��"Input n:"
// **�����ʽҪ��"Fib(%d)=%d, count=%d\n"
// ��������ʾ�����£�
// Input n:10
// Fib(1)=1, count=1
// Fib(2)=1, count=3
// Fib(3)=2, count=5
// Fib(4)=3, count=9
// Fib(5)=5, count=15
// Fib(6)=8, count=25
// Fib(7)=13, count=41
// Fib(8)=21, count=67
// Fib(9)=34, count=109
// Fib(10)=55, count=177
// ˵��:�������Ϊn=0��n=1

#include <stdio.h>
// int count;
// int main()
// {
//     int n;
//     printf("Input n:");
//     scanf("%d", &n);
//     int num;
//     for (int i = 0; i < n; i++)
//     {
//         count = 0;
//         num=F(i+1);
//         printf("Fib(%d)=%d, count=%d\n", i + 1, num, count);
//     }
// }

// int F(int n)
// {
//     count++;
//     if (n == 0)
//     {
//         return 0;
//     }
//     else if (n == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return F(n - 1) + F(n - 2);
//     }
// }

int main()
{
    int f1 = 1;
    int f2 = 1;
    int f3 = 1;
    int num=0;
    num+=f1;
    num+=f2;
    for (int i = 0; i < 18; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
        num+=f3;
    }
}