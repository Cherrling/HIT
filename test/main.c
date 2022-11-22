#include <stdio.h>
#include <stdlib.h>//分配动态数组地址空间所需头文件
void main()
{
	int i;
	int size;
	int *arry;
	printf("输入数组长度：");
	scanf("%d",&size);
	arry=(int *)malloc(size*sizeof(int));
	//利用void* malloc (size_t size)函数分配数组地址空间大小，以字节为单位

	for(i=0;i<size;i++)
	{
		arry[i]=i;
		//*(arry+i)=i;//指针型数据指引
	}
	for(i=0;i<size;i++)
	{
		printf("%d\r\n",*(arry+i));//使用指针引导数据
		//printf("%d\r\n",arry[i]);
	}
	free(arry);//不使用数组后，利用void free (void* ptr)函数释放动态数组存储区
}
