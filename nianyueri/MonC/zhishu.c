

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
bool ss(n)
{
    if (n==2)
    {
        /* code */
    }
    
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
    
    for (int i = 2; i < n-1; i++)
    {
        if (n%i==0)
        {
            return 0;
        }
        
    }
    return 1;
    
 
 
}