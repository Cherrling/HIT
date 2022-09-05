#include<stdio.h>

int main(){
    char ch;
    printf("Enter a character:");
    scanf("%c",&ch);
    printf("%c %c %c\n",ch-1,ch,ch+1);
    printf("%d %d %d\n",ch-1,ch,ch+1);
    return 0;
}