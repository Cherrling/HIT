#include<stdio.h>
#include<stdbool.h>

int IsPerfect(int x){
    if (x==1)
    {
        return 0;
    }
    int sum=0;
    for (int i = 1; i < x; i++)
    {
        if (x%i==0)
        {
            sum+=i;
        }
        
    }
    
    if (sum==x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
    



}

int main(){
    printf("Input m:\n");
    int n;
    scanf("%d",&n);
    if (IsPerfect(n))
    {
        /* code */
        printf("%d is a perfect number\n",n);


    }
    else
    {
        printf("%d is not a perfect number\n",n);
    }



}