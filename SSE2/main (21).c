#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// ��д����ʵ�����º�����



// ������ʾ��Ϣ��"input x:\n" �����ʽ��"%f" �����ʽ��"y=%.3f" ��������ʾ��1�� input x: 0�L y=6.000 ��������ʾ��2�� input x: 21�L y=39.000

int main(){
    printf("input x:\n");
    float n,y;
    scanf("%f",&n);
    if (n>=-7&&n<=10)
    {
        y=5*n*n-4*n+6;
    }else
    {
        y=n/3+32;
    }
    printf("y=%.3f",y);
    
}