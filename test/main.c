#include <stdio.h>
#include <stdlib.h>//���䶯̬�����ַ�ռ�����ͷ�ļ�
void main()
{
	int i;
	int size;
	int *arry;
	printf("�������鳤�ȣ�");
	scanf("%d",&size);
	arry=(int *)malloc(size*sizeof(int));
	//����void* malloc (size_t size)�������������ַ�ռ��С�����ֽ�Ϊ��λ

	for(i=0;i<size;i++)
	{
		arry[i]=i;
		//*(arry+i)=i;//ָ��������ָ��
	}
	for(i=0;i<size;i++)
	{
		printf("%d\r\n",*(arry+i));//ʹ��ָ����������
		//printf("%d\r\n",arry[i]);
	}
	free(arry);//��ʹ�����������void free (void* ptr)�����ͷŶ�̬����洢��
}
