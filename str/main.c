#include<stdio.h>
void Count(char*s,int*ptotal,int*pCapital,int*pLowercase,int*pDigit);
int main(){
    char s[35];
    int total=0,Capital=0,Lowercase=0,Digit=0;
    gets(s);
    Count(s,&total,&Capital,&Lowercase,&Digit);
    printf("total=%d,Capital=%d,Lowercase=%d,Digit=%d",total,Capital,Lowercase,Digit);
    if(total>=6&&Capital>=1&&Lowercase>=1&&Digit>=1)printf("Succeed");
    else printf("Failed");
    return 0;

    
}
void Count(char*s,int*ptotal,int*pCapital,int*pLowercase,int*pDigit)
{

    for(s;*s!='\0';s++)
    {
        (*ptotal)++;
        if(*s>='a'&&*s<='z')(*pLowercase)++;
        else if(*s>='A'&&*s<='Z')(*pCapital)++;
        else if(*s>='0'&&*s<='9')(*pDigit)++;

    }
}
