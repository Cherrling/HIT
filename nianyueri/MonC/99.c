#include <stdio.h>

int main()
{

	int i, j;
	for (i = 1; i <= 9; i++)
	{ // ��ѭ����ѭ��9��
		for (j = 9; j >0; j--)
		{									   // ��ѭ��������ѭ���ı���Ϊ��Χ
			printf("%d*%d=%d  ", j, i, i * j); // ע��i��j���Ⱥ�˳�򣬿���
		}
		printf("\n"); // ��������ѭ������
	}

	

	return 0;
}
