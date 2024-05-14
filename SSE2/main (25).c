#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//  a 90
//  b 60
//  c 88


struct score
{
    char name[100];
    int a;
    float x;
};

void selection_sort(int a[], int len) 
{
    int i,j,temp;
 
    for (i = 0 ; i < len - 1 ; i++) 
    {
        int min = i;                  // 记录最小值，第一个元素默认最小
        for (j = i + 1; j < len; j++)     // 访问未排序的元素
        {
            if (a[j] < a[min])    // 找到目前最小值
            {
                min = j;    // 记录最小值
            }
        }
        if(min != i)
        {
            temp=a[min];  // 交换两个变量
            a[min]=a[i];
            a[i]=temp;


            struct score t1;


            t1=stu[i];
            stu[i]=stu[i+1];
            stu[i+1]=t1;
        }
        /* swap(&a[min], &a[i]);  */   // 使用自定义函数交換
    }
}
 
/*
void swap(int *a,int *b) // 交换两个变量
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
int main(){
    struct score stu1;
    struct score stu2;
    struct score stu3;

    strcmp(stu1.name, "a");
    strcmp(stu2.name, "b");
    strcmp(stu3.name, "c");

    stu1.x=90;
    stu2.x=60;
    stu3.x=88;


}