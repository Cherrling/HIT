#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool ss(n){
        
		for(int i=5; i*i<=n; i+=6) {
			if(n%i==0 || n%(i+2)==0) {
				return false;
			}
		}
    return true;
    
    
}







int main(){
    int n=0;
    int sum=5;

    printf("Input n:");

    scanf("%d",&n);


    switch (n)
    {
    case 1:
        printf("sum=0");
        break;
    case 2:
        printf("sum=2");
        break;
    case 3:
        printf("sum=5");
        break;
    case 4:
        printf("sum=5");
        break;
    default:
    
        for (int i = 5; i <=n; i+=6)
        {
            if (ss(i))
            {
                sum+=i;
            }
            if ((i+2)<=n)
            {
                if (ss(i+2))
                {
                    sum+=(i+2);
                }
                
            }
            
            
                
        }
            
        break;
        }
        
    printf("sum = %d\n",sum);



    }

