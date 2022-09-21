#include<stdio.h>

long fact(int n){
    long res=1;
    for (int i = 2; i <= n; i++)
    {
        res*=i;
    }
    return res;
    
}

int C(int m ,int n){
    return ((fact(m)/(fact(m-n)*fact(n))));
}