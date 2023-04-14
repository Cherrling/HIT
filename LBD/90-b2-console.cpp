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
//"┍""┯""─""┑""│" "┕""┷""┙"
// │─ ┤├ ┴ ┬ ┼ ┘└ ┐┌
void print_console(int a[9][9], int hang, int lie, int line)
{
	if (line)
	{
		cct_cls();
		cct_setconsoleborder(4 * (lie + 1), 2 * hang + 5);
		cout << "当前窗口大小为" << 2 * (hang) + 5 << "行" << 4 * (lie + 1) << "列" << endl;

		cct_setcolor(COLOR_WHITE, COLOR_BLACK);
		cout << "┍";
		Sleep(5);

		for (int i = 0; i < lie - 1; i++)
		{
			cout << "─";
			Sleep(5);
			cout << "┯";
			Sleep(5);
		}
		cout << "─";
		Sleep(5);
		cout << "┑";
		Sleep(5);

		cout << endl;

		for (int i = 0; i < hang; i++)
		{
			cout << "│";
			Sleep(5);

			for (int j = 0; j < lie; j++)
			{
				if (a[i][j] == 0)
				{
					cout << "  ";
					Sleep(5);

					cout << "│";
					Sleep(5);
				}
				else
				{
					cct_setcolor(a[i][j] + 7, COLOR_WHITE);
					cout << "○";
					Sleep(5);

					cct_setcolor(COLOR_WHITE, COLOR_BLACK);
					cout << "│";
					Sleep(5);
				}
			}
			cout << endl;

			if (i == hang - 1)
			{

				cout << "└";
				Sleep(5);

				for (int i = 0; i < lie - 1; i++)
				{
					cout << "─";
					Sleep(5);
					cout << "┴";
					Sleep(5);
				}
				cout << "─";
				cout << "┘";
				cout << endl;
			}
			else
			{
				cout << "├";
				Sleep(5);

				for (int i = 0; i < lie - 1; i++)
				{
					cout << "─";
					Sleep(5);
					cout << "┼";
					Sleep(5);
				}
				cout << "─";
				cout << "┤";
				cout << endl;
			}
		}
	}
	else
	{
		cct_cls();
		cct_setconsoleborder(2 * (lie + 2) + 1, hang + 10);
		cout << "当前窗口大小为" << 2 * (hang) + 5 << "行" << 4 * (lie + 1) << "列" << endl;

		cct_setcolor(COLOR_WHITE, COLOR_BLACK);
		cout << "┍";
		Sleep(5);
		for (int i = 0; i < hang; i++)
		{
			cout << "─";
			Sleep(5);
		}
		cout << "┑" << endl;
		Sleep(5);

		for (int i = 0; i < hang; i++)
		{
			cout << "│";
			Sleep(5);
			for (int j = 0; j < lie; j++)
			{

				if (a[i][j] == 0)
				{
					cout << "  ";
					Sleep(5);
				}
				else
				{
					cct_setcolor(a[i][j] + 7, COLOR_WHITE);
					cout << "○";
					Sleep(5);
					cct_setcolor(COLOR_WHITE, COLOR_BLACK);
				}
			}
			cout << "│" << endl;
			Sleep(5);
		}

		cout << "┕";
		Sleep(5);
		for (int i = 0; i < hang; i++)
		{
			cout << "─";
			Sleep(5);
		}
		cout << "┙" << endl;
	}
	cct_setcolor();
}

void GUI(int a[9][9], int hang, int lie)
{
	// │─ ┤├ ┴ ┬ ┼ ┘└ ┐┌

	cct_setconsoleborder(70, 23);

	cout << "屏幕：23行70列" << endl;

	cout << "┌";
	for (int i = 0; i < lie - 1; i++)
	{
		cout << "─┬";
	}
	cout << "─┐";

	for (int i = 0; i < hang; i++)
	{
		for (int i = 0; i < hang; i++)
		{
			cout << "│";
			for (int j = 0; j < lie; j++)
			{

				if (a[i][j] == 0)
				{
					cout << "  ";
				}
				else
				{
					cct_setcolor(a[i][j] + 7, COLOR_WHITE);
					cout << "○";
					cct_setcolor(COLOR_WHITE, COLOR_BLACK);
				}
			}
			cout << "│" << endl;
		}
	}

	cout << "┕";
	Sleep(5);
	for (int i = 0; i < hang; i++)
	{
		cout << "─";
		Sleep(5);
	}
	cout << "┙" << endl;

	cct_showstr(4 * (lie + 1), 2, "┌─────┐");
	cct_showstr(4 * (lie + 1), 3, "│得分：0   │");
	cct_showstr(4 * (lie + 1), 4, "└─────┘");

	cct_showstr(4 * (lie + 1), 2, "┌─────┐");
	cct_showstr(4 * (lie + 1), 7, "│─│─│─│");
	cct_showstr(4 * (lie + 1), 8, "└─────┘");

	cct_showstr(4 * (lie + 1), 10, "┌────────────┐");
	cct_showstr(4 * (lie + 1), 11, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 12, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 13, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 14, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 15, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 16, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 17, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 18, "│○:00/()消除-0│");
	cct_showstr(4 * (lie + 1), 19, "└────────────┘");



}