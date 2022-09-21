#include<stdio.h>

int main(){
    int num;
    scanf("%d",&num);
    int carpet[num][4];
    int px,py;
    int output=-1;
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d %d %d",&carpet[i][0],&carpet[i][1],&carpet[i][2],&carpet[i][3]);
    }

    scanf("%d %d",&px,&py);

    for (int j = 0; j < num; j++)
    {
        if ((carpet[j][0])<=px && (carpet[j][0]+carpet[j][2])>=px&&(carpet[j][1])<=py && (carpet[j][1]+carpet[j][3]>=py))
        {
            output=j+1;
        }
        
    }
    

    printf("%d",output);


    



}