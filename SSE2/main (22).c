#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 比较两个整数的大小。
// **输入格式要求："%d%d"  提示信息："Enter integer X and Y:"
// **输出格式要求："X>Y\n"  "X<Y\n"  "X=Y\n"
// 程序运行示例如下：
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