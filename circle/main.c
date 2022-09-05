#include<stdio.h>

int main(){

    float r,s,c;

    printf("请输入花坛的半径 \n");
    scanf("%f",&r);

    c=2*3.14*r;
    s=3.14*r*r;

    printf("花坛的周长为：%f \n",c);
    printf("花坛的面积为：%f \n",s);
    return 0;


}