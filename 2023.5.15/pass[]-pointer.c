#include <stdio.h>
 
/* 函数声明 */
double getAverage(int *arr, int size);
 
int main ()
{
   /* 带有 5 个元素的整型数组  */
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
  printf("%d\n",balance[0]);
   avg = getAverage( balance, 5 ) ;

  printf("%d\n",balance[0]);
   /* 传递一个指向数组的指针作为参数 */
 
   /* 输出返回值  */
   printf("Average value is: %f\n", avg );
   
   return 0;
}

double getAverage(int arr[], int size)
{
  int    i, sum = 0;      
  double avg;          
 
  for (i = 0; i < size; ++i)
  {
    sum += arr[i];
  }
 arr[0]=-1;
  avg = (double)sum / size;
 
  return avg;
}