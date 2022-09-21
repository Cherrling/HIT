#include<stdio.h>

int main(){
    int n;
    int line;
    int x,y;
    scanf("%d",&n);
    for (int i = 0; i < 10000; i++)
    {
        if (i*(i+1)/2>=n)
        {
            line=i;
            break;
        }
        
    }

        int num=n-(line*(line-1)/2);
        num-=1;
    if (line%2==0)
    {
        x=1;
        y=line;
        for (int i = 0; i < num; i++)
        {
            x+=1;
            y-=1;
        }

    }
    else{
        x=line;
        y=1;
        for (int i = 0; i < num; i++)
        {
            x-=1;
            y+=1;
        }
    }
    
    printf("%d/%d",x,y);

}