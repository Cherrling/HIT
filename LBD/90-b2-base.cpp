/* 2251647 国07 张凯 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

/*内部数组的打印*/
void base_print(int hang, int lie, int a[9][9])
{
	int i, j;

	cout << "  |";
	for (i = 0; i < lie; i++)
	{
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "--+";
	for (i = 0; i < 3 * lie + 1; i++)
	{
		cout << "-";
	}
	cout << endl;
	for (i = 0; i < hang; i++)
	{
		cout << char('A' + i) << " |";
		for (j = 0; j < lie; j++)
		{
			cout << "  ";
			if (a[i][j])
			{
				cct_setcolor(COLOR_HYELLOW, a[i][j]);
			}
			cout << a[i][j];
			cct_setcolor();
		}
		cout << endl;
	}
}

/*搜索路径*/
void search_2(int hang, int lie, int h_1, int l_1, int h_2, int l_2, int a[9][9])
{
	int b[9][9] = {0}, path[9][9] = {0}, queue_h[100] = {0}, queue_l[100] = {0}, head = 0, tail = 0;

	queue_h[tail] = h_1;
	queue_l[tail] = l_1;
	tail++;

	while ((queue_h[head] != h_2 || queue_l[head] != l_2) && head != tail)
	{
		if (queue_h[head] > 0 && a[queue_h[head] - 1][queue_l[head]] == 0 && b[queue_h[head] - 1][queue_l[head]] == 0)
		{
			queue_h[tail] = queue_h[head] - 1;
			queue_l[tail] = queue_l[head];
			tail++;
			b[queue_h[head] - 1][queue_l[head]] = 100 + queue_h[head] * 10 + queue_l[head];
		}
		if (queue_l[head] > 0 && a[queue_h[head]][queue_l[head] - 1] == 0 && b[queue_h[head]][queue_l[head] - 1] == 0)
		{
			queue_h[tail] = queue_h[head];
			queue_l[tail] = queue_l[head] - 1;
			tail++;
			b[queue_h[head]][queue_l[head] - 1] = 100 + queue_h[head] * 10 + queue_l[head];
		}
		if (queue_h[head] < hang - 1 && a[queue_h[head] + 1][queue_l[head]] == 0 && b[queue_h[head] + 1][queue_l[head]] == 0)
		{
			queue_h[tail] = queue_h[head] + 1;
			queue_l[tail] = queue_l[head];
			tail++;
			b[queue_h[head] + 1][queue_l[head]] = 100 + queue_h[head] * 10 + queue_l[head];
		}
		if (queue_l[head] < lie - 1 && a[queue_h[head]][queue_l[head] + 1] == 0 && b[queue_h[head]][queue_l[head] + 1] == 0)
		{
			queue_h[tail] = queue_h[head];
			queue_l[tail] = queue_l[head] + 1;
			tail++;
			b[queue_h[head]][queue_l[head] + 1] = 100 + queue_h[head] * 10 + queue_l[head];
		}
		head++;
	}

	if (queue_h[head] == h_2 && queue_l[head] == l_2)
	{
		path[h_2][l_2] = 1;
		int i = b[h_2][l_2], j;
		while (i / 10 % 10 != h_1 || i % 10 != l_1)
		{
			path[i / 10 % 10][i % 10] = 1;
			i = b[i / 10 % 10][i % 10];
			cout << i << endl;
		}
		if (h_1 >= 0 && h_1 <= 8 && l_1 >= 0 && l_1 <= 8)
		{
			path[h_1][l_1] = 1;
		}
		cout << endl;
		cout << "查找结果数组：" << endl;
		cout << "  |";
		for (i = 0; i < lie; i++)
		{
			cout << setw(3) << i + 1;
		}
		cout << endl;
		cout << "--+";
		for (i = 0; i < 3 * lie + 1; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (i = 0; i < hang; i++)
		{
			cout << char('A' + i) << " |";
			for (j = 0; j < lie; j++)
			{
				cout << "  ";
				if (path[i][j] == 0)
				{
					cout << "0";
				}
				else
				{
					cout << "*";
				}
			}
			cout << endl;
		}
		cout << endl;
		cout << "移动路径<不同色标识>：" << endl;
		cout << "  |";
		for (i = 0; i < lie; i++)
		{
			cout << setw(3) << i + 1;
		}
		cout << endl;
		cout << "--+";
		for (i = 0; i < 3 * lie + 1; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (i = 0; i < hang; i++)
		{
			cout << char('A' + i) << " |";
			for (j = 0; j < lie; j++)
			{
				cout << "  ";
				if (path[i][j] == 1)
				{
					cct_setcolor(COLOR_HYELLOW, a[i][j]);
				}
				cout << a[i][j];
				cct_setcolor();
			}
			cout << endl;
		}
	}
	else
	{
		cout << "无法找到移动路径" << endl;
	}
}

int judge(int hang, int lie, int h_1, int l_1, int h_2, int l_2, int a[9][9])
{
	int b[9][9] = {0}, queue_h[100] = {0}, queue_l[100] = {0}, head = 0, tail = 0;

	queue_h[tail] = h_1;
	queue_l[tail] = l_1;
	tail++;

	while ((queue_h[head] != h_2 || queue_l[head] != l_2) && head != tail)
	{
		if (queue_h[head] > 0 && a[queue_h[head] - 1][queue_l[head]] == 0 && b[queue_h[head] - 1][queue_l[head]] == 0)
		{
			queue_h[tail] = queue_h[head] - 1;
			queue_l[tail] = queue_l[head];
			tail++;
			b[queue_h[head] - 1][queue_l[head]] = 1;
		}
		if (queue_l[head] > 0 && a[queue_h[head]][queue_l[head] - 1] == 0 && b[queue_h[head]][queue_l[head] - 1] == 0)
		{
			queue_h[tail] = queue_h[head];
			queue_l[tail] = queue_l[head] - 1;
			tail++;
			b[queue_h[head]][queue_l[head] - 1] = 1;
		}
		if (queue_h[head] < hang - 1 && a[queue_h[head] + 1][queue_l[head]] == 0 && b[queue_h[head] + 1][queue_l[head]] == 0)
		{
			queue_h[tail] = queue_h[head] + 1;
			queue_l[tail] = queue_l[head];
			tail++;
			b[queue_h[head] + 1][queue_l[head]] = 1;
		}
		if (queue_l[head] < lie - 1 && a[queue_h[head]][queue_l[head] + 1] == 0 && b[queue_h[head]][queue_l[head] + 1] == 0)
		{
			queue_h[tail] = queue_h[head];
			queue_l[tail] = queue_l[head] + 1;
			tail++;
			b[queue_h[head]][queue_l[head] + 1] = 1;
		}
		head++;
	}

	if (queue_h[head] == h_2 && queue_l[head] == l_2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int clean(int a[9][9], int hang, int lie, int *p)
{
	int i, j, k, n = 1, score = 0, clean[9][9] = {0};

	// 横向消除
	for (i = 0; i < hang; i++)
	{
		for (j = 1; j < lie; j++)
		{
			cout << "横" << endl;
			if (a[i][j] == a[i][j - 1] && a[i][j] != 0)
			{
				n++;
			}
			if (a[i][j] != a[i][j - 1] || j >= lie - 1)
			{
				if (n >= 5)
				{
					score += (n - 1) * (n - 2);
					for (k = 0; k < n; k++)
					{
						clean[i][j - k - 1] = 1;
					}
					if (a[i][j] == a[i][j - 1])
					{
						clean[i][j] = 1;
					}

					break;
				}
				else
				{
					n = 1;
				}
			}
		}
		n = 1;
	}
	cout << "/*" << endl;

	// 纵向消除
	for (j = 0; j < lie; j++)
	{
		for (i = 1; i < hang; i++)
		{
			cout << "横" << endl;
			if (a[i][j] == a[i - 1][j] && a[i][j] != 0)
			{
				n++;
			}
			if (a[i][j] != a[i - 1][j] || i >= hang - 1)
			{
				if (n >= 5)
				{
					score += (n - 1) * (n - 2);
					for (k = 0; k < n; k++)
					{
						clean[i - k - 1][j] = 1;
					}
					if (a[i][j] == a[i - 1][j])
					{
						clean[i][j] = 1;
					}
					break;
				}
				else
				{
					n = 1;
				}
			}
		}
		n = 1;
	}
	cout << "/*" << endl;

	// 左上到右下消除
	for (i = 0; i < hang - 4; i++)
	{
		for (j = 1;; j++)
		{
			cout << "左上到右下" << endl;
			if (a[i + j][j] == a[i + j - 1][j - 1] && a[i + j][j] != 0)
			{
				n++;
			}
			if (a[i + j][j] != a[i + j - 1][j - 1] || (i + j) >= hang - 1 || j >= lie - 1)
			{
				if (n >= 5)
				{
					score += (n - 1) * (n - 2);
					for (k = 0; k < n; k++)
					{
						clean[i + j - k - 1][j - k - 1] = 1;
					}
					if (a[i + j][j] == a[i + j - 1][j - 1])
					{
						clean[i + j][j] = 1;
					}
					break;
				}
				else
				{
					n = 1;
					break;
				}
			}
		}
		n = 1;
	}
	cout << "/*" << endl;

	for (i = 1; i < lie - 4; i++)
	{
		for (j = 1;; j++)
		{
			if (a[j][i + j] == a[j - 1][i + j - 1] && a[j][i + j] != 0)
			{
				n++;
			}
			if (a[j][i + j] != a[j - 1][i + j - 1] || (i + j) >= hang - 1 || j >= lie - 1)
			{
				if (n >= 5)
				{
					score += (n - 1) * (n - 2);
					for (k = 0; k < n; k++)
					{
						clean[j - k - 1][i + j - k - 1] = 1;
					}
					if (a[j][i + j] == a[j - 1][i + j - 1])
					{
						clean[j][i + j] = 1;
					}
					break;
				}
				else
				{
					n = 1;
					break;
				}
			}
		}

		n = 1;
	}
	cout << "/*" << endl;
	// 右上到左下消除
	for (i = 0; i < hang - 4; i++)
	{
		for (j = 1; lie - 1 - j >= 0; j++)
		{
			cout << "右上到左下" << endl;
			if (a[i + j][lie - 1 - j] == a[i + j - 1][lie - j] && a[i + j][lie - 1 - j] != 0)
			{
				n++;
			}
			if (a[i + j][lie - 1 - j] != a[i + j - 1][lie - j] || i + j >= hang - 1 || j <= 0)
			{
				if (n >= 5)
				{
					score += (n - 1) * (n - 2);
					for (k = 0; k < n; k++)
					{
						clean[i + j - 1 - k][hang - j + k] = 1;
					}
					if (a[i + j][lie - 1 - j] == a[i + j - 1][lie - j])
					{
						clean[i + j][lie - 1 - j] = 1;
					}

					break;
				}
			}
		}

		n = 1;
	}
	cout << "/*" << endl;
	for (i = lie - 1; i > 4; i--)
	{
		for (j = 1;; j++)
		{
			if (a[j][i - j] == a[j - 1][i - j + 1] && a[j][i - j] != 0)
			{
				n++;
			}
			if (a[j][i - j] == a[j - 1][i - j + 1] || i + j >= hang - 1 || j <= 0)
			{
				if (n >= 5)
				{
					score += (n - 1) * (n - 2);
					for (k = 0; k < n; k++)
					{
						clean[j - k - 1][i - j + k + 1] = 1;
					}
					if (a[j][i - j] == a[j - 1][i - j + 1])
					{
						clean[j][i - j] = 1;
					}

					break;
				}
			}
		}

		n = 1;
	}
	cout << "/*" << endl;

	int *q = &clean[0][0];
	for (i = 0; i < 81; i++)
	{
		if (*q != 0)
		{
			*p = 0;
		}
		p++;
		q++;
	}
	return score;
}

int if_over(int hang, int lie, int a[9][9])
{

	int i, j, sum_0 = 0;

	for (i = 0; i < hang; i++)
	{
		for (j = 0; j < lie; j++)
		{
			if (a[i][j] == 0)
			{
				sum_0++;
			}
		}
	}
	if (sum_0 == 0 || sum_0 == hang * lie)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void base_game(int hang, int lie, int a[9][9])
{
	int score = 0, score_last = 0, random_h, random_l;
	int *p = &a[0][0];
	while (if_over(hang, lie, a) == 0)
	{
		cout << "当前数组：" << endl;
		base_print(hang, lie, a);
		cout << endl;
		cout << "下三个彩球的颜色分别是：";
		int r[3];
		r[0] = rand() % 7 + 1;
		r[1] = rand() % 7 + 1;
		r[2] = rand() % 7 + 1;
		cout << r[0] << " " << r[1] << " " << r[2] << endl;
		char point_1[20] = {0}, point_2[20] = {0};
		int x, y, i;
		cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
		cct_getxy(x, y);
		while (1)
		{
			for (i = 0; i < 20; i++)
			{
				point_1[i] = _getch();
				cout << point_1[i];
				if (point_1[i] >= 'a' && point_1[i] <= 'z')
				{
					point_1[i] -= 32;
				}
				if (point_1[i] == '\r' || i == 19)
				{
					break;
				}
			}
			if (point_1[0] - 'A' >= 0 && point_1[0] - 'A' <= hang - 1 && point_1[1] - '1' >= 0 && point_1[1] - '1' <= lie - 1)
			{
				cct_gotoxy(0, y + 1);
				if (a[point_1[0] - 'A'][point_1[1] - '1'] == 0)
				{
					cout << "起始位置为空，请重新输入                ";
					cct_gotoxy(x, y);
					cout << setw(20) << " ";
					cct_gotoxy(x, y);
					continue;
				}
				else
				{
					cout << "输入为" << point_1[0] << "行" << int(point_1[1] - '0') << "列                ";
					break;
				}
			}
			else
			{
				cct_gotoxy(0, y + 1);
				cout << "输入错误，请重新输入                ";
				cct_gotoxy(x, y);
				cout << setw(20) << " ";
				cct_gotoxy(x, y);
				continue;
			}
		}
		cct_gotoxy(0, y + 2);
		cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
		cct_getxy(x, y);
		while (1)
		{
			for (i = 0; i < 20; i++)
			{
				point_2[i] = _getch();
				cout << point_2[i];
				if (point_2[i] >= 'a' && point_2[i] <= 'z')
				{
					point_2[i] -= 32;
				}
				if (point_2[i] == '\r' || i == 19)
				{
					break;
				}
			}
			if (point_2[0] - 'A' >= 0 && point_2[0] - 'A' <= hang - 1 && point_2[1] - '1' >= 0 && point_2[1] - '1' <= lie - 1)
			{
				cct_gotoxy(0, y + 1);
				if (a[point_2[0] - 'A'][point_2[1] - '1'] != 0)
				{
					cout << "目标位置非空，请重新输入                ";
					cct_gotoxy(x, y);
					cout << setw(20) << " ";
					cct_gotoxy(x, y);
					continue;
				}
				else
				{
					cout << "输入为" << point_2[0] << "行" << int(point_2[1] - '0') << "列                ";
					break;
				}
			}
			else
			{
				cct_gotoxy(0, y + 1);
				cout << "输入错误，请重新输入                ";
				cct_gotoxy(x, y);
				cout << setw(20) << " ";
				cct_gotoxy(x, y);
				continue;
			}
		}
		cout << endl;
		if (judge(hang, lie, int(point_1[0] - 'A'), int(point_1[1] - '1'), int(point_2[0] - 'A'), int(point_2[1] - '1'), a) == 1)
		{
			cout << "/*" << endl;
			a[int(point_2[0] - 'A')][int(point_2[1] - '1')] = a[int(point_1[0] - 'A')][int(point_1[1] - '1')];
			a[int(point_1[0] - 'A')][int(point_1[1] - '1')] = 0;
			cout << "/*" << endl;
			score_last = score;
			cout << "/*" << endl;
			score += clean(a, hang, lie, p);
			cout << "/*" << endl;
			for (i = 0; i < 3;)
			{
				random_h = rand() % hang;
				random_l = rand() % lie;
				if (a[random_h][random_l] == 0)
				{
					a[random_h][random_l] = r[i];
					i++;
				}
				if (if_over(hang, lie, a) == 1)
				{
					break;
				}
			}
			cout << "/*" << endl;
			score += clean(a, hang, lie, p);
			cout << "移动后的数组<不同色标识>：" << endl;
			base_print(hang, lie, a);
			cout << endl;
			cout << "本次得分：" << score - score_last << " 总得分：" << score << endl;
		}
		else
		{
			cout << "无法找到移动路径" << endl;
		}
	}
}