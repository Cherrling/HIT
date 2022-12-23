#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>
int length = -1;
int node_size;
int* map = NULL;
int i, j;
int difficulty;
int trap[4][2];
int win = 0;
ExMessage m; // 定义消息变量
struct data
{
    int order;
    int time;
    int difficulty;
    int score;
};
typedef struct node
{
    struct data data;
    struct node* next;
} NODE;
NODE* head = NULL;

NODE* winadd(int time, int score)
{

    NODE* p;

    p = (NODE*)malloc(sizeof(NODE));
    if (p == NULL)
    {
        exit(0);
    }
    else
    {
        if (head == NULL)
        {
            head = p;
            p->data.order = 1;
            p->data.time = time;
            p->data.difficulty = difficulty;
            p->data.score = score;
            p->next = NULL;
        }
        else
        {
            NODE* t = head;
            int i = 2;
            for (; t->next != NULL;)
            {
                t = t->next;
                i++;
            }
            p->data.order = i;
            p->data.time = time;
            p->data.difficulty = difficulty;
            p->data.score = score;
            t->next = p;
            p->next = NULL;
        }
        printf("win");
        printf("%d\n", p->data.score);
    }

    return head;
}

void chainsort()
{
    struct data tmp;
    if (head != NULL)
    {
        for (NODE* t = head; t->next != NULL; t = t->next)
        {
            for (NODE* p = head; p->next != NULL; p = p->next)
            {
                if (p->data.score < (p->next)->data.score)
                {
                    tmp = p->data;
                    p->data = p->next->data;
                    p->next->data = tmp;
                }
            }
        }
    }
}

int setsize()
{
    cleardevice();
    int size[4][4] = {
        150,
        350,
        1080 - 750,
        720 - 250,
        //
        350,
        350,
        1080 - 550,
        720 - 250,
        //
        550,
        350,
        1080 - 350,
        720 - 250,
        //
        750,
        350,
        1080 - 150,
        720 - 250,
    };
    int leng[4] = { 7, 15, 31, 51 };
    setlinecolor(BLACK);
    for (int i = 0; i < 4; i++)
    {
        roundrect(size[i][0], size[i][1], size[i][2], size[i][3], 10, 10);
    }

    LOGFONT f;
    gettextstyle(&f);                      // 获取当前字体设置
    f.lfHeight = 256;                      // 设置字体高度为 48
    _tcscpy(f.lfFaceName, _T("Consolas")); // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
    f.lfQuality = ANTIALIASED_QUALITY;     // 设置输出效果为抗锯齿
    settextstyle(&f);                      // 设置字体样式
    settextcolor(BLACK);
    outtextxy(150, 0, _T("MAZE"));

    while (true)
    {

        // 获取一条鼠标或按键消息
        m = getmessage(EX_MOUSE | EX_KEY);

        switch (m.message)
        {
        case WM_LBUTTONDOWN:
            for (int k = 0; k < 4; k++)
            {
                if (m.x >= size[k][0] && m.y >= size[k][1] && m.x <= size[k][2] && m.y <= size[k][3])
                {
                    difficulty = k;
                    length = leng[k];
                    node_size = (int)(720.0 / (float)length);
                    return 0;
                }
            }
        case WM_KEYDOWN:
            if (m.vkcode == VK_ESCAPE)
                return -1; // 按 ESC 键退出程序
        }
    }
}

int dup(int move[4], int n)
{
    for (int i = 0; i < 4; i++)
    {
        if (move[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

void randdig(int move[4])
{
    int r = 0;
    for (int i = 0; i < 4;)
    {
        r = rand() % 4;
        if (!dup(move, r))
        {
            move[i] = r;
            i++;
        }
    }
}

void genpath(int x, int y)
{

    *(map + x * length + y) = 1;
    int move[4] = { -1, -1, -1, -1 };
    randdig(move);
    for (int k = 0; k < 4; k++)
    {
        if (move[k] == 0)
        {
            if ((x - 2) > 0 && !*(map + (x - 2) * length + y))
            {
                *(map + (x - 1) * length + y) = 1, genpath(x - 2, y);
            }
        }
        if (move[k] == 1)
        {
            if ((x + 2) < length && !*(map + (x + 2) * length + y))
            {
                *(map + (x + 1) * length + y) = 1, genpath(x + 2, y);
            }
        }
        if (move[k] == 2)
        {
            if ((y - 2) > 0 && !*(map + (x)*length + y - 2))
            {
                *(map + (x)*length + y - 1) = 1, genpath(x, y - 2);
            }
        }
        if (move[k] == 3)
        {
            if ((y + 2) < length && !*(map + (x)*length + y + 2))
            {
                *(map + (x)*length + y + 1) = 1, genpath(x, y + 2);
            }
        }
    }
}

void resetmap()
{
    for (int k = 0; k < length * length; k++)
    {
        *(map + k) = 0;
    }
    *(map + 1 * length + 0) = 1;
    *(map + (length - 2) * length + length - 1) = 1;
    genpath(1, 1);
}

void pmove(int prei, int prej)
{
    clearrectangle(prej * node_size, prei * node_size, (prej + 1) * node_size, (prei + 1) * node_size);
    setfillcolor(BLUE);
    fillroundrect(j * node_size + node_size * 0.1, i * node_size + node_size * 0.1, (j + 1) * node_size - node_size * 0.1, (i + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
}

int move(char direction)

{
    switch (direction)
    {
    case 'w':
        if (*(map + (i - 1) * length + j) && i - 1 >= 0)
        {
            i--;
        }
        return 1;
    case 'a':
        if (*(map + i * length + j - 1) && j - 1 >= 0)
        {
            j--;
        }
        return 1;
    case 's':
        if (*(map + (i + 1) * length + j) && i + 1 < length)
        {
            i++;
        }
        return 1;
    case 'd':
        if (*(map + i * length + j + 1) && j + 1 < length)
        {
            j++;
        }
        return 1;
    default:
        return 0;
    }
}

void pout()
{
    cleardevice();
    BeginBatchDraw();
    for (int x = 0; x < length; x++)
    {
        for (int y = 0; y < length; y++)
        {
            setfillcolor(BLACK);
            if (*(map + x * length + y) == 0)
            {
                fillroundrect(y * node_size + node_size * 0.1, x * node_size + node_size * 0.1, (y + 1) * node_size - node_size * 0.1, (x + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
            }
            setfillcolor(RED);
            for (int k = 0; k < 4; k++)
            {
                if (x == trap[k][0] && y == trap[k][1] && x != 0 && y != 0)
                {
                    fillroundrect(y * node_size + node_size * 0.1, x * node_size + node_size * 0.1, (y + 1) * node_size - node_size * 0.1, (x + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
                }
            }
        }
    }


    settextstyle(24, 0, "Consolas", 0, 0, 700, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH);                 // 设置字体样式
    settextcolor(BLACK);
    outtextxy(750, 0, _T("使用小写wasd进行移动"));
    outtextxy(750, 25, _T("按r刷新地图"));
    outtextxy(750, 50, _T("按q修改难度"));
    outtextxy(750, 75, _T("按Esc退出"));
    outtextxy(750, 100, _T("获胜次数"));
    char number[5];
    char sen[100];
    sprintf(number, "%d", win);
    // outtextxy(850,100,number);

    chainsort();
    NODE* t = head;
    int num = 1;
    if (t != NULL)
    {
        while (1)
        {
            strcat(sen, "第");

            sprintf(number, "%d", t->data.order);
            strcat(sen, number);

            strcat(sen, "次在难度");

            sprintf(number, "%d", t->data.difficulty);
            strcat(sen, number);

            strcat(sen, "下耗时");


            sprintf(number, "%d", t->data.time);
            strcat(sen, number);
            strcat(sen, "秒，积分");

            sprintf(number, "%d", t->data.score);
            strcat(sen, number);

            //outtextxy(750, 100 + 25 * num, sen);
            printf("%s",sen);

            printf("%d\n", t->data.score);
            if (t->next == NULL)
            {
                break;
            }
            t = t->next;
        }
    }
    EndBatchDraw();
}

void gentrap()
{
    int x, y;
    for (int k = 0; k < 4; k++)
    {
        trap[k][0] = 0;
        trap[k][1] = 0;
    }
    for (int k = 0; k < difficulty; k++)
    {
        if (rand() % 10 <= 7)
        {
            while (1)
            {
                x = (rand() % ((length - 1) / 2)) * 2 + 1;
                y = (rand() % ((length - 1) / 2)) * 2 + 1;
                if ((x == 1 && y == 1) || (x == length - 1 && y == length - 1))
                {
                    continue;
                }
                for (int l = 0; l < 4; l++)
                {
                    if (x == trap[l][0] && y == trap[l][1])
                    {
                        continue;
                    }
                }
                break;
            }
            trap[k][0] = x;
            trap[k][1] = y;
        }
    }
}

int single_game()
{
    int st, et;
    int prei, prej;
    st = time(NULL);
    gentrap();

    pout();
    pmove(i, j);
    while (1)
    {
        m = getmessage(EX_CHAR);
        flushmessage();
        if (m.vkcode == VK_ESCAPE)
        {
            return -1; // 按 ESC 键退出程序
        }
        else if (m.ch == 'r')
        {
            break;
        }
        else if (m.ch == 'q')
        {
            if (setsize() == -1)
            {
                return -1;
            }
            printf("%d", length);
            delete[] map;
            map = new int[length * length];
            break;
        }
        else if (m.ch == 'w' || m.ch == 'a' || m.ch == 's' || m.ch == 'd')
        {
            prei = i;
            prej = j;
            if (move(m.ch))
            {
                pmove(prei, prej);
                for (int k = 0; k < 4; k++)
                {
                    //踩到陷阱
                    if (i == trap[k][0] && j == trap[k][1])
                    {
                        resetmap();
                        gentrap();
                        pout();
                        pmove(i, j);
                    }
                }

                if (i == length - 2 && j == length - 1)
                {
                    et = time(NULL);
                    win++;
                    int score = (difficulty + 1) * (difficulty + 1) * 100 / (et - st);
                    head = winadd((et - st), score);
                    break;
                }
            }
        }
    }
    return 0;
}
int main()
{
    initgraph(1080, 720);
    setbkcolor(RGB(255, 248, 220));
    if (setsize() == -1)
    {
        return 0;
    }

    map = new int[length * length];
    srand(GetTickCount());

    while (1)
    {
        resetmap();
        i = 1, j = 0;
        if (single_game() == -1)
        {
            break;
        }
    }
    free(map);
}