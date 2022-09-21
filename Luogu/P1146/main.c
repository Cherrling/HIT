#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",n);
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        coin[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i!=j)
            {
                coin[j]=coin[j]?0:1;
            }
            
        }
    for (int i = 0; i < n; i++)
    {
        printf("%d",coin[i]);
    }
    printf("\n");
    
        
    }
    
    

}