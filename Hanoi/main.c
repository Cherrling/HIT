#include<stdio.h>
#define N 100
int hanoi(int n,char a,char b, char c);
int move(int n,char a,char b);
int num=0;
int main(){
    int n;
    char a,b,c;
    scanf("%d %c %c %c",&n,&a,&b,&c);
    hanoi(n,a,b,c);
    printf("%d",num);
    return 0;
}
int move(int n,char a,char b){
    printf("Move %d from %c to %c \n",n,a,b);
    num+=1;
    return 0;
}
int hanoi(int n,char a,char b, char c){
    if (n==1)
    {
        move(n,a,c);
    }
    else
    {
        hanoi(n-1,a,c,b);
        move(n,a,c);
        hanoi(n-1,b,a,c);
    }
    return 0;
}