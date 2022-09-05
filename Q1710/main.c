#include<stdio.h>
#include<stdbool.h>
int main(){
    int n;
    printf("Please enter a number:");
    scanf("%d",&n);
    bool flag=true;

    if (n<2&&n>=0)
    {
        printf("It is not a prime number.No divisor!\n");
    }
    else if(n>=2)
    {
        for (int i = 2; i < n; i++)
        {

            if (n%i==0)
            {
                printf("%d\n",i);
                flag=false;
            }
        
        }


        if (flag)
        {
            printf("It is a prime number.No divisor!\n");
        }
        
    }else   if(n<-2)
    {        for (int i = n+1; i <0 ; i++)
        {

            if (n%i==0)
            {
                return 0;
                // printf("%d\n",i);
            }
        
        }
    }else
    {
         printf("It is not a prime number.No divisor!\n");
    }
    
    
    

return 0;

    

}