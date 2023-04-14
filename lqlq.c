#include<stdio.h>
int main()
{
	int a=3, b=4, c=5;
	float x=1.2, y=2.4, z=-3.6;
	unsigned u=51274;
	long n=128765;
	char c1='a', c2='b';
	printf("a= %d b= %d c= %d\n",a,b,c);
	printf("x=%f,y=%f,z=%f\n",x,y,z);
	printf("x+y= %.2f y+z=%.2f z+x=%.2f\n",x+y,y+z,z+x);
    printf("u= %d n= %ld\n",u,n);
    printf("c1='%c' or %d(ascii)\n",c1,c1);
    printf("c2='%c' or %d(ascii)\n",c2,c2);

	
}