#include<stdio.h>
#include<stdlib.h>
#include<string.h>



// ��дһ�������������һ��������������ķ��š�
// **�����ʽҪ��"%d" ��ʾ��Ϣ��"Enter n:"
// **�����ʽҪ��"+\n" "-\n" "this number has no sign\n"
// ��������ʾ��1���£�
// Enter n:90
// +
// ��������ʾ��2���£�
// Enter n:0
// this number has no sign

int main(){
    printf("Enter n:");
    int n;
    scanf("%d",&n);
    if (n==0)
    {
        printf("this number has no sign\n");
    }else if (n>0)
    {
        printf("+\n");
    }else{
        printf("-\n");
    }
    
    

}