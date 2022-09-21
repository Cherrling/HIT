#include <graphics.h>
#include <iostream>
using namespace std;

int a[15][15] = { 0 };
MOUSEMSG mouse;
int tx[4][9] = { {4,3,2,1,0,-1,-2,-3,-4}, {0,0,0,0,0,0,0,0,0}, {4,3,2,1,0,-1,-2,-3,-4}, {4,3,2,1,0,-1,-2,-3,-4} };
int ty[4][9] = { {0,0,0,0,0,0,0,0,0}, {4,3,2,1,0,-1,-2,-3,-4}, {4,3,2,1,0,-1,-2,-3,-4}, {-4,-3,-2,-1,0,1,2,3,4} };

void init();
int change(int k);
void draw_Black(int x, int y);
void draw_White(int x, int y);
bool check_win(int person, int x, int y);
void show(int person);

int main() {
	init();
	FlushMouseMsgBuffer();
	int x, y;
	int person = 1;
	while (1) {
		mouse = GetMouseMsg();
		if (mouse.uMsg == WM_LBUTTONDOWN) {
			x = change(mouse.x);
			y = change(mouse.y);
			if (x >= 0 && x < 15 && y >= 0 && y < 15) {
				if (a[x][y] == 0) {
					if (person == 1) {
						draw_Black(x, y);
						a[x][y] = person;
						if (check_win(person, x, y)) {
							show(person);
							system("pause");
						}
						person = 2;
					}
					else {
						draw_White(x, y);
						a[x][y] = person;
						if (check_win(person, x, y)) {
							show(person);
							system("pause");
						}
						person = 1;
					}
				}
			}
		}
	}
}

void init() {
	initgraph(720, 600);
	setlinecolor(WHITE);
	for (int i = 50; i <= 500; i += 30) {
		line(50, i, 500, i);
	}
	for (int i = 50; i <= 500; i += 30) {
		line(i, 50, i, 500);
	}
}

int change(int k) {
	int n = (k - 50) / 30;
	int n1 = (k - 50) % 30;
	if (n1 > 0) {
		n = n + 1;
	}
	return n - 1;
}

void draw_Black(int x, int y) {
	setfillcolor(BLACK);
	int x1 = 50 + x * 30 + 15;
	int y1 = 50 + y * 30 + 15;
	fillcircle(x1, y1, 10);
}

void draw_White(int x, int y) {
	setfillcolor(WHITE);
	int x1 = 50 + x * 30 + 15;
	int y1 = 50 + y * 30 + 15;
	fillcircle(x1, y1, 10);
}

bool check_win(int person, int x, int y) {
	int x1, y1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0, k = 4; k < 9; j++, k++) {
			int bo = false;
			for (int w = j; w <= k; w++) {
				x1 = x + tx[i][w];
				y1 = y + ty[i][w];
				if (x1 < 0 || x1 >= 15 || y1 < 0 || y1 >= 15) {
					bo = true;
					break;
				}
				if (a[x1][y1] != person) {
					bo = true;
					break;
				}
			}
			if (bo) {
				continue;
			}
			else {
				return true;
			}
		}
	}
	return false;
}

void show(int person) {
	cleardevice();
	settextcolor(RGB(60, 100, 150));
	settextstyle(80, 20, _T("Î¢ÈíÑÅºÚ"));
	if (person == 1) {
		outtextxy(130, 350, _T("ºÚ·½Ê¤£¡"));
	}
	else {
		outtextxy(130, 350, _T("°×·½Ê¤£¡"));
	}
}
