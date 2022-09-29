#include<stdio.h>
int main()
{       
    int num,n;
    int a[4];
    for (int i = 1; i < 100; i++)
    {
        num=i*i;
        n=num;
        for (int j = 0; j < 4; j++)
        {
            a[j]=num%10;
            num=num/10;
        }
        if (a[0]==a[1]&&a[2]==a[3]&&a[0]!=a[2])
        {
            printf("The number is:%d\n",n);
            return 0;
        }
        
    }
    return 0;

}