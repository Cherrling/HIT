#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �Ƚ����������Ĵ�С��
// **�����ʽҪ��"%d%d"  ��ʾ��Ϣ��"Enter integer X and Y:"
// **�����ʽҪ��"X>Y\n"  "X<Y\n"  "X=Y\n"
// ��������ʾ�����£�
// Enter integer X and Y:5 6
// X<Y


int main(){
    printf("Enter integer X and Y:");
    int x,y;
    scanf("%d%d",&x,&y);
    if (x==y)
    {
        printf("X=Y\n");
    }else if (x>y)
    {
        printf("X>Y\n");
    }else{
        printf("X<Y\n");
    }
    
    
}