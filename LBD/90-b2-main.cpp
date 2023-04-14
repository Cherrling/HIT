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

int menu()
{
    int choice;
    cout << "--------------------------------------------" << endl;
    cout << "1.内部数组，随机生成初始5个球" << endl;
    cout << "2.内部数组，随机生成60%的球，寻找移动路径" << endl;
    cout << "3.内部数组，完整版" << endl;
    cout << "4.画出n*n的框架（无分割线），随机显示五个球" << endl;
    cout << "5.画出n*n的框架（有分割线），随机显示五个球" << endl;
    cout << "6.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
    cout << "7.cmd图形界面完整版" << endl;
    cout << "0.退出" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "[请选择:]";

    while (1) {
        choice = _getch() - '0';
        if (choice >= 0 && choice <= 7) {
            cout << choice;
            break;
        }
    }
    Sleep(200);
    return choice;
}

int main()
{
    srand((unsigned)time(NULL));
    int choice;

    while (1) {
        choice = menu();

        cct_cls();

        int hang = 0, lie = 0;
        while (1) {
            cout << "请输入行数(7-9)：" << endl;
            cin >> hang;

            if (cin.good() == 1 && (hang >= 7 && hang <= 9)) {
                cin.ignore(2251647, '\n');
                break;
            }
            cin.clear();
            cin.ignore(2251647, '\n');
        }
        while (1) {
            cout << "请输入列数(7-9)：" << endl;
            cin >> lie;

            if (cin.good() == 1 && (lie >= 7 && lie <= 9)) {
                cin.ignore(2251647, '\n');
                break;
            }
            cin.clear();
            cin.ignore(2251647, '\n');
        }

        int a[9][9] = { 0 }, i, num, random_1, random_2, x, y;

        if (choice == 2 || choice == 6) {
            num = int(hang * lie * 0.6);
        }
        else {
            num = 5;
        }
        for (i = 0; i < num;) {
            random_1 = rand() % hang;
            random_2 = rand() % lie;
            if (a[random_1][random_2] == 0) {
                a[random_1][random_2] = rand() % 7 + 1;
                i++;
            }
        }
        if (choice == 1) {
            cout << "初始数组：" << endl;
            base_print(hang, lie, a);
        }
        if (choice == 2) {
            cout << "初始数组：" << endl;
            base_print(hang, lie, a);
            cout << endl;
            cout << "下三个彩球的颜色分别是：";
            int r1, r2, r3;
            r1 = rand() % 7 + 1;
            r2 = rand() % 7 + 1;
            r3 = rand() % 7 + 1;
            cout << r1 << " " << r2 << " " << r3 << endl;
            char point_1[20] = { 0 }, point_2[20] = { 0 };
            // char point_1,point_2;
            cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
            cct_getxy(x, y);
            while (1) {
                for (i = 0; i < 20; i++) {
                    point_1[i] = _getch();
                    cout << point_1[i];
                    if (point_1[i] >= 'a' && point_1[i] <= 'z') {
                        point_1[i] -= 32;
                    }
                    if (point_1[i] == '\r' || i == 19) {
                        break;
                    }
                }
                if (point_1[0] - 'A' >= 0 && point_1[0] - 'A' <= hang - 1 && point_1[1] - '1' >= 0 && point_1[1] - '1' <= lie - 1) {
                    cct_gotoxy(0, y + 1);
                    if (a[point_1[0] - 'A'][point_1[1] - '1'] == 0) {
                        cout << "起始位置为空，请重新输入                ";
                        cct_gotoxy(x, y);
                        cout << setw(20) << " ";
                        cct_gotoxy(x, y);
                        continue;
                    }
                    else {
                        cout << "输入为" << point_1[0] << "行" << int(point_1[1] - '0') << "列                ";
                        break;
                    }

                }
                else {
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
            while (1) {
                for (i = 0; i < 20; i++) {
                    point_2[i] = _getch();
                    cout << point_2[i];
                    if (point_2[i] >= 'a' && point_2[i] <= 'z') {
                        point_2[i] -= 32;
                    }
                    if (point_2[i] == '\r' || i == 19) {
                        break;
                    }
                }
                if (point_2[0] - 'A' >= 0 && point_2[0] - 'A' <= hang - 1 && point_2[1] - '1' >= 0 && point_2[1] - '1' <= lie - 1) {
                    cct_gotoxy(0, y + 1);
                    if (a[point_2[0] - 'A'][point_2[1] - '1'] != 0) {
                        cout << "目标位置非空，请重新输入                ";
                        cct_gotoxy(x, y);
                        cout << setw(20) << " ";
                        cct_gotoxy(x, y);
                        continue;
                    }
                    else {
                        cout << "输入为" << point_2[0] << "行" << int(point_2[1] - '0') << "列                ";
                        break;
                    }
                }
                else {
                    cct_gotoxy(0, y + 1);
                    cout << "输入错误，请重新输入                ";
                    cct_gotoxy(x, y);
                    cout << setw(20) << " ";
                    cct_gotoxy(x, y);
                    continue;
                }
            }
            cout << endl;
            search_2(hang, lie, int(point_1[0] - 'A'), int(point_1[1] - '1'), int(point_2[0] - 'A'), int(point_2[1] - '1'), a);
        }
        if (choice == 3) {
            base_game(hang, lie, a);

        }

        cout << endl << "本小题结束，请输入End继续...";
        cct_getxy(x, y);
        char ch[20] = { 0 };
        while (1) {
            for (i = 0; i < 20; i++) {
                ch[i] = _getch();
                if (ch[i] != '\r') {
                    cout << ch[i];
                }
                if (ch[i] >= 'a' && ch[i] <= 'z') {
                    ch[i] -= 32;
                }
                if (ch[i] == '\r' || i == 19) {
                    break;
                }
            }
            if (ch[0] != 'E' || ch[1] != 'N' || ch[2] != 'D') {
                cct_gotoxy(0, y + 1);
                cout << "输入错误，请重新输入";
                cct_gotoxy(x, y);
                cout << setw(20) << " ";
                cct_gotoxy(x, y);
                for (i = 0; i < 20; i++) {
                    ch[i] = 0;
                }
                continue;
            }
            else {
                break;
            }
        }
        cct_setcolor();
        cct_cls();
        cct_gotoxy(0, 0);
    }

    return 0;
}