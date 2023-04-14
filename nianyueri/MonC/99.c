#include <stdio.h>

int main()
{

	int i, j;
	for (i = 1; i <= 9; i++)
	{ // 外循环，循环9次
		for (j = 9; j >0; j--)
		{									   // 内循环，以外循环的变量为范围
			printf("%d*%d=%d  ", j, i, i * j); // 注意i和j的先后顺序，看题
		}
		printf("\n"); // 不可在内循环体内
	}

	

	return 0;
}
