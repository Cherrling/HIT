#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include<math.h>

// 编写程序实现以下功能：从键盘输入任意三个数a，b，c，若a，b，c的值能构成三角形，则计算并输出三角形的面积，否则打印输出不是三角形。已知计算三角形面积的公式为：
//      s=(a+b+c)/2
//     area=sqrt(s(s-a)(s-b)(s-c))
// ***输入提示信息："Input a,b,c:"
// ***输入数据格式："%f,%f,%f"
// ***输出格式要求：
//     若是三角形，则输出数据格式为："area=%.4f\n"
//   若不是三角形，则输出数据格式为："It is not a triangle\n"

int main()
{
    float a,b,c,s,area;
    printf("Input a,b,c:");
    scanf("%f,%f,%f",&a,&b,&c);
    if (a+b>c&&a+c>b&&b+c>a)
    {
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        printf("area=%.4f\n",area);
    }
    else
    {
        printf("It is not a triangle\n");
    }
    return 0;
    
}