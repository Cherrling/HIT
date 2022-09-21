#include<stdio.h>

int main(){
    int l,m;
    scanf("%d %d",&l,&m);
    l+=1;
    int sub[m][2];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d",&sub[i][0],&sub[i][1]);
    }
    int road[l];
    for (int j = 0; j < l; j++)
    {
        road[j]=1;
    }

    for (int k = 0; k < m; k++)
    {
        for (int o = sub[k][0]; o <= sub[k][1]; o++)
        {
                road[o]=0;
        }
        
    }
    int num=0;
    for (int p = 0; p < l; p++)
    {
            num+=road[p];
    }
    
    printf("%d",num);




}