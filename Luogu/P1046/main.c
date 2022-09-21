#include<stdio.h>

int main(){
    int apple[10];
    int height;
    int num=0;
    scanf("%d %d %d %d %d %d %d %d %d %d",&apple[0],&apple[1],&apple[2],&apple[3],&apple[4],&apple[5],&apple[6],&apple[7],&apple[8],&apple[9]);
    scanf("%d",&height);
    for (int i = 0; i < 10; i++)
    {
        if ((height+30)>=apple[i])
        {
            num+=1;
        }
        
    }
    printf("%d",num);
    return 0;
    
}