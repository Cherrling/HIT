#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib")
#include <stdio.h>
#include <time.h>
#include <cstdio>
#include <graphics.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int length = -1;                 //地图大小
char bestname[10] = "Anonymous"; //最好成绩用户姓名
char name[10] = "Anonymous";     //当前用户名
float best = 0;                  //历史最高分数
int node_size;                   //单个方块的大小
int *map = NULL;                 //存储地图的数组
int i, j;                        //玩家当前的坐标
int difficulty;                  //当前模式的难度
int trap[4][2];                  //随机生成的陷阱坐标
int treasure[3][2];              //随机生成的宝藏坐标
int win = 0;                     //玩家胜利次数
ExMessage m;                     // 定义消息变量
struct data                      //存储玩家胜利数据的单个结构体
{
    int order;
    float time;
    int difficulty;
    float score;
};
typedef struct node //用于链表的结构体节点
{
    struct data data;
    struct node *next;
} NODE;

NODE *head = NULL; //链表的头指针

//动态添加链表节点，用于记录用户胜利的相关信息
//包括胜利的次序，游玩难度，所用时间和得分情况
NODE *winadd(float time, float score)
{

    NODE *p;

    p = (NODE *)malloc(sizeof(NODE)); //申请内存空间
    if (p == NULL)                    //未申请成功则退出，并报错
    {
        exit(0);
    }
    else
    {
        //当头指针为空，即第一次创建链表时，给头指针赋值并记录相关信息
        if (head == NULL)
        {
            head = p;
            p->data.order = 1;
            p->data.time = time;
            p->data.difficulty = difficulty;
            p->data.score = score;
            p->next = NULL;
        }
        else //当头指针不为空，即第二次及以后记录胜利信息时
        {
            NODE *t = head;
            int i = 2;
            for (; t->next != NULL;) //遍历至链表末端
            {
                t = t->next;
                i++;
            }
            //对链表末端新节点进行赋值
            p->data.order = i;
            p->data.time = time;
            p->data.difficulty = difficulty;
            p->data.score = score;
            t->next = p;
            p->next = NULL;
        }
    }

    return head; //返回头指针
}

//链表排序函数，主要根据每次胜利所得分数的高低进行排序
//采用冒泡排序方法，使数据由高到低排序
void chainsort(NODE *head)
{
    struct data tmp;
    if (head != NULL) //仅当头指针不为空，即至少存在一次胜利信息时，才执行排序
    {
        for (NODE *t = head; t->next != NULL; t = t->next)
        {
            for (NODE *p = head; p->next != NULL; p = p->next)
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

//对于开始游戏窗口的绘制
// 当传参ifname==1时，判断需要记录用户姓名
int start(int ifname = 0)
{ //清空窗口内容
    cleardevice();

    // size数组存储了四个难度按钮所需要的逻辑坐标
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

    // leng数组存储了四种难度对应的地图边长
    int leng[4] = {7, 15, 31, 51};

    setlinecolor(BLACK);
    // 遍历，绘制难度选项
    for (int i = 0; i < 4; i++)
    {
        roundrect(size[i][0],
                  size[i][1],
                  size[i][2],
                  size[i][3], 10, 10);
    }

    settextstyle(256, 0, "Consolas", 0, 0, 700, false, false, false,
                 DEFAULT_CHARSET,
                 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                 PROOF_QUALITY, DEFAULT_PITCH);
    settextcolor(BLACK);
    outtextxy(300, 0, _T("MAZE"));
    settextstyle(64, 0, "Consolas", 0, 0, 700, false, false, false,
                 DEFAULT_CHARSET,
                 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                 PROOF_QUALITY, DEFAULT_PITCH); // 设置字体样式
    outtextxy(180, 380, _T("简单"));
    outtextxy(380, 380, _T("普通"));
    outtextxy(580, 380, _T("困难"));
    outtextxy(780, 380, _T("大师"));

    // 当传参ifname==1时，判断需要记录用户姓名
    if (ifname)
    {
        // 记录用户姓名并存入name字符串中
        InputBox(name, 10, "请输入你的名字：", "MAZE",
                 "Anonymous", 0, 0, false);
    }

    // 采用while循环对鼠标坐标进行检测
    while (true)
    {

        // 获取一条鼠标或按键消息
        m = getmessage(EX_MOUSE | EX_KEY);

        switch (m.message)
        {
            // 当检测到鼠标单击时
        case WM_LBUTTONDOWN:
            // 对鼠标坐标进行遍历，判断是否点击难度选项
            for (int k = 0; k < 4; k++)
            {
                if (m.x >= size[k][0] &&
                    m.y >= size[k][1] &&
                    m.x <= size[k][2] &&
                    m.y <= size[k][3])
                {
                    // 用户点击难度选项后，对相关参数进行赋值
                    difficulty = k;
                    length = leng[k];
                    node_size = (int)(720.0 / (float)length);
                    return 0;
                }
            }
            // 当检测到按键操作时
        case WM_KEYDOWN:
            // 判断用户按下Esc，函数返回-1表示退出程序
            if (m.vkcode == VK_ESCAPE)
                return -1; // 按 ESC 键退出程序
        }
    }
}

//判断是否重复函数，检测当前操作是否已被包含在move数组中
int dup(int move[4], int n)
{
    for (int i = 0; i < 4; i++)
    {
        // 确认重复则返回1，否则返回0
        if (move[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

// 产生随机方向函数，每次调用时以随机顺序产生上下左右四个方向分别对应0，1，2，3
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

// 随机产生地图的核心函数，主要依据随机方向顺序进行地图的随机生成
// 使用到的算法有递归和深度优先搜索
void genpath(int x, int y)
{
    // 将传参得到的坐标值在地图上标为1
    *(map + x * length + y) = 1;

    // 定义移动顺序数组，并调用randdig函数进行随机产生方向顺序
    int move[4] = {-1, -1, -1, -1};
    randdig(move);

    // 对move数组进行遍历
    for (int k = 0; k < 4; k++)
    {
        if (move[k] == 0)
        {
            // 对于传参得到的坐标值，假如对应方向的坐标尚未被标记为道路，
            //并且未越界，则标记此方向为通路，同时标记该方向中间块为通路
            if ((x - 2) > 0 && !*(map + (x - 2) * length + y))
            {
                *(map + (x - 1) * length + y) = 1;
                // if判定可标记道路后，采用深度优先算法，直接调用自身对该方向进行递归操作
                genpath(x - 2, y);
            }
        }
        // 以下方向同理
        if (move[k] == 1)
        {
            if ((x + 2) < length && !*(map + (x + 2) * length + y))
            {
                *(map + (x + 1) * length + y) = 1;
                genpath(x + 2, y);
            }
        }
        if (move[k] == 2)
        {
            if ((y - 2) > 0 && !*(map + (x)*length + y - 2))
            {
                *(map + (x)*length + y - 1) = 1;
                genpath(x, y - 2);
            }
        }
        if (move[k] == 3)
        {
            if ((y + 2) < length && !*(map + (x)*length + y + 2))
            {
                *(map + (x)*length + y + 1) = 1;
                genpath(x, y + 2);
            }
        }
    }
}

// 重置地图函数，使地图除出入口以外的所有方块被标记为0
// 同时调用genpath函数进行地图的随机生成
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

// 绘制玩家移动函数，先对玩家上一位置坐标进行清除操作，再基于当前坐标值绘制玩家当前位置
void pmove(int prei, int prej)
{
    clearrectangle(prej * node_size + 1,
                   prei * node_size + 1,
                   (prej + 1) * node_size - 1,
                   (prei + 1) * node_size - 1);
    setfillcolor(BLUE);
    fillroundrect(j * node_size + node_size * 0.1,
                  i * node_size + node_size * 0.1,
                  (j + 1) * node_size - node_size * 0.1,
                  (i + 1) * node_size - node_size * 0.1,
                  (float)node_size * 0.4, (float)node_size * 0.4);
}

// 移动函数，主要判定玩家是否可向对应方向移动
int move(char direction)

{
    switch (direction)
    {
    case 'w':
        // 假如玩家移动方向为通路且未越界，判定玩家坐标移动
        // 以下方向同理
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

// 界面绘制函数，主要负责整个迷宫界面的绘制
void pout()
{
    // 使用批量绘制函数，防止一次性绘制大量内容时造成屏幕闪烁
    BeginBatchDraw();
    cleardevice(); //清空当前屏幕内容

    // 两层循环遍历地图的所有位置
    for (int x = 0; x < length; x++)
    {
        for (int y = 0; y < length; y++)
        {
            // 设置颜色为黑色，样式为斜线，进行迷宫围墙的绘制
            setfillcolor(BLACK);
            setfillstyle(BS_HATCHED, HS_BDIAGONAL);
            if (*(map + x * length + y) == 0)
            {

                fillrectangle(y * node_size,
                              x * node_size,
                              (y + 1) * node_size,
                              (x + 1) * node_size);
            }

            // 设置颜色为红色，样式为全填充，进行陷阱块的绘制
            setfillstyle(BS_SOLID);
            setfillcolor(RED);
            for (int k = 0; k < 4; k++)
            {
                if (x == trap[k][0] && y == trap[k][1] && x != 0 && y != 0)
                {
                    fillroundrect(y * node_size + node_size * 0.1,
                                  x * node_size + node_size * 0.1,
                                  (y + 1) * node_size - node_size * 0.1,
                                  (x + 1) * node_size - node_size * 0.1,
                                  (float)node_size * 0.4, (float)node_size * 0.4);
                }
            }
            // 设置颜色为金色，样式为全填充，进行宝藏块的绘制

            setfillcolor(RGB(255, 215, 0));
            for (int k = 0; k < 3; k++)
            {
                if (x == treasure[k][0] &&
                    y == treasure[k][1] &&
                    x != 0 && y != 0)
                {
                    fillroundrect(y * node_size + node_size * 0.1,
                                  x * node_size + node_size * 0.1,
                                  (y + 1) * node_size - node_size * 0.1,
                                  (x + 1) * node_size - node_size * 0.1,
                                  (float)node_size * 0.4, (float)node_size * 0.4);
                }
            }
        }
    }

    // 对于屏幕提示信息的绘制
    settextstyle(24, 0, "Consolas", 0, 0, 700, false, false, false,
                 DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                 CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH); // 设置字体样式
    settextcolor(BLACK);
    outtextxy(750, 0, _T("使用小写wasd进行移动"));
    outtextxy(750, 25, _T("按r刷新地图"));
    outtextxy(750, 50, _T("按q修改难度"));
    outtextxy(750, 75, _T("按Esc退出"));

    setfillcolor(RED);
    fillroundrect(752, 102, 773, 123, 25 * 0.4, 25 * 0.4);
    outtextxy(780, 100, _T("为陷阱，触碰时会刷新地图"));

    setfillcolor(RGB(255, 215, 0));
    fillroundrect(752, 127, 773, 148, 25 * 0.4, 25 * 0.4);
    outtextxy(780, 125, _T("为宝藏，触碰时加10分"));

    // 对于玩家已获胜次数的绘制，获胜次数存储在win变量中
    outtextxy(750, 150, _T("获胜次数:"));
    char number[12];
    char sen[200] = {};
    sprintf(number, "%d", win);
    outtextxy(880, 150, number);

    // 对于历史最高分的绘制，获胜次数存储在best和bestname变量中
    outtextxy(750, 175, _T("历史最高分:"));
    outtextxy(880, 175, bestname);
    sprintf(number, "%.2f", best);
    outtextxy(1000, 175, number);

    // 对于玩家当次游玩的排行榜设置
    outtextxy(750, 200, _T("排行榜"));

    chainsort(head); //首先进行链表中数据的排序

    // 遍历链表，并打印其中的内容
    // 包括获胜时的难度，所用时间和所得分数
    NODE *t = head;
    int num = 1;
    if (t != NULL)
    {
        while (1)
        {
            settextstyle(20, 0, "Consolas", 0, 0, 700, false, false, false,
                         DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                         CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH); // 设置字体样式
            strcpy(sen, "");

            // strcat(sen, "第");

            // sprintf(number, "%d", t->data.order);
            // strcat(sen, number);

            // strcat(sen, "次游戏在");
            char diff[4][8] = {"简单", "普通", "困难", "大师"};
            strcat(sen, diff[t->data.difficulty]);

            strcat(sen, "难度耗时");

            sprintf(number, "%.2f", t->data.time);
            strcat(sen, number);
            strcat(sen, "秒，得分");

            sprintf(number, "%.2f", t->data.score);
            strcat(sen, number);

            outtextxy(750, 200 + 22 * num, sen);
            num++;
            if (t->next == NULL)
            {
                break;
            }
            t = t->next;
        }
    }
    EndBatchDraw();
}

// 随机生成陷阱坐标函数
// 对于四种难度，分别最多只会生成0，1，2，3个陷阱
// 每次判定陷阱是否产生的概率为80%
void gentrap()
{
    int x, y;
    // 清空陷阱坐标数组
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
                // 坐标判定，防止陷阱生成在出入口处
                if ((x == 1 && y == 1) || (x == length - 1 && y == length - 1))
                {
                    continue;
                }
                // 坐标判定，防止陷阱生成在已有的陷阱位置上
                for (int l = 0; l < 4; l++)
                {
                    if (x == trap[l][0] && y == trap[l][1])
                    {
                        continue;
                    }
                }
                // 坐标判定，防止陷阱生成在宝藏位置上
                for (int l = 0; l < 4; l++)
                {
                    if (x == treasure[l][0] && y == treasure[l][1])
                    {
                        continue;
                    }
                }
                break;
            }
            // 成功生成陷阱坐标后进行赋值
            trap[k][0] = x;
            trap[k][1] = y;
        }
    }
}

// 随机生成宝藏坐标函数
// 对于简单难度，会生成1个宝藏
// 对于普通及以上难度，有30%概率生成2个宝藏，70%概率生成3个宝藏
void gentreasure()
{
    int x, y;
    for (int k = 0; k < 3; k++)
    {
        treasure[k][0] = 0;
        treasure[k][1] = 0;
    }
    int num = 1;
    if (difficulty)
    {
        num++;
        if (rand() % 10 <= 7)
        {
            num++;
        }
    }

    for (int k = 0; k < num; k++)
    {

        while (1)
        {
            x = (rand() % ((length - 1) / 2)) * 2 + 1;
            y = (rand() % ((length - 1) / 2)) * 2 + 1;
            // 坐标判定，防宝藏阱生成在出入口处
            if ((x == 1 && y == 1) || (x == length - 1 && y == length - 1))
            {
                continue;
            }
            // 坐标判定，防止宝藏生成在陷阱位置上
            for (int l = 0; l < 4; l++)
            {
                if (x == trap[l][0] && y == trap[l][1])
                {
                    continue;
                }
            }
            // 坐标判定，防止宝藏生成在已有的宝藏位置上
            for (int l = 0; l < 4; l++)
            {
                if (x == treasure[l][0] && y == treasure[l][1])
                {
                    continue;
                }
            }
            break;
        }
        // 成功生成宝藏坐标后进行赋值
        treasure[k][0] = x;
        treasure[k][1] = y;
    }
}

// 对于每张地图，都会调用一次single_game函数
int single_game()
{
    int st, et;          //初始化开始，结束时间
    int prei, prej;      //存储玩家上一位置
    float score = 0;     //存储当前轮次得分，初始值为0
    st = GetTickCount(); //设置开始时间，单位毫秒
    gentrap();           //随机生成陷阱坐标
    gentreasure();       //随机生成宝藏坐标
    pout();              //绘制迷宫地图及提示信息，排行榜等
    pmove(i, j);         //初始化绘制玩家坐标

    // 使用while函数进行玩家按键的判定
    while (1)
    {

        m = getmessage(EX_CHAR); //定义消息变量
        flushmessage();          //清空消息缓冲区
                                 // 按 ESC 键退出程序
        if (m.vkcode == VK_ESCAPE)
        {
            return -1;
        }
        //按r键跳出循环，结束single_game函数，以实现地图的刷新
        else if (m.ch == 'r')
        {
            break;
        }
        //按q键时，调用start函数，使用户重新选择难度，
        //并根据用户选择的难度重新分配map使用的内存空间，实现动态数组
        else if (m.ch == 'q')
        {
            if (start() == -1)
            {
                return -1;
            }
            delete[] map;                   //释放原map数组内存
            map = new int[length * length]; //重新分配新map地图空间
            break;
        }
        //用户使用wasd进行移动时
        else if (m.ch == 'w' || m.ch == 'a' || m.ch == 's' || m.ch == 'd')
        {
            // 记录用户当前坐标
            prei = i;
            prej = j;
            // 判定用户是否能成功移动
            if (move(m.ch))
            {
                // 如果能移动，绘制用户的新位置
                pmove(prei, prej);

                // 循环遍历用户是否踩到陷阱
                for (int k = 0; k < 4; k++)
                {
                    //踩到陷阱时，重新生成地图，同时重新生成新的陷阱坐标，并再次绘制用户位置
                    if (i == trap[k][0] && j == trap[k][1])
                    {
                        resetmap();
                        gentrap();
                        pout();
                        pmove(i, j);
                    }
                }
                // 循环遍历用户是否踩到宝藏
                for (int k = 0; k < 3; k++)
                {
                    //踩到宝藏时，用户得分加10，同时清除当前宝藏
                    if (i == treasure[k][0] && j == treasure[k][1])
                    {
                        score += 10;
                        treasure[k][0] = 0;
                        treasure[k][1] = 0;
                    }
                }

                // 判定用户是否走到出口
                if (i == length - 2 && j == length - 1)
                {
                    // 用户走到出口时，记录结束时间，同时使获胜次数加1
                    et = GetTickCount();
                    win++;
                    // 使用函数计算用户得分
                    score += (float)((difficulty + 1) * (difficulty + 1) * 100 * 1000) / (float)(et - st);
                    // 如果用户得分打破了最高分纪录，则更新最高分记录
                    if (score >= best)
                    {
                        best = score;
                        strcpy(bestname, name);
                        FILE *fp = fopen("best.dat", "wb");
                        fprintf(fp, "%s %f", bestname, best);
                        fclose(fp);
                    }
                    // 使链表新增节点，记录用户胜利信息
                    head = winadd((float)(et - st) / 1000.0, score);
                    break;
                }
            }
        }
    }
    return 0;
}
int main()
{
    // 设置主窗口，并设置背景颜色
    initgraph(1080, 720);
    setbkcolor(RGB(255, 248, 220));
    PlaySound(TEXT("bk.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    // 调用start函数绘制开始界面，如果用户按Esc，则结束函数
    if (start(1) == -1)
    {
        return 0;
    }

    // 文件操作，尝试读取最高分存档
    FILE *fp = fopen("best.dat", "rb");
    if (fp != NULL)
    {
        // 如果读取到存档，读取存档中的姓名和分数到bestname，best变量中
        fscanf(fp, "%s %f", bestname, &best);
        fclose(fp);
    }
    else
    {
        // 如果未读取到存档，则新建存档并存入初始值
        FILE *fp = fopen("best.dat", "wb");
        fprintf(fp, "%s %f", "Anonymous", 0);
        fclose(fp);
    }

    // 记录先前存档中的最高分
    float prebest = best;

    // 使用动态数组创建map数组，用于地图的存放
    map = new int[length * length];

    // 使用时间值作为随机数种子
    srand(GetTickCount());

    // 使用循环重复进行游戏
    // 当single_game函数返回-1时，判断用户退出，则退出函数
    while (1)
    {
        // 重置地图数据
        resetmap();
        // 重置玩家坐标
        i = 1, j = 0;
        // 进入单局游戏
        if (single_game() == -1)
        {
            break;
        }
    }

    // 用户退出时，如果当前次游玩打破之前最高分记录，则将新最高分写入存档中
    if (best > prebest)
    {
        FILE *fp = fopen("best.dat", "wb");
        fprintf(fp, "%s %f", bestname, best);
        fclose(fp);
    }
    // 释放地图占用的内存空间
    free(map);
    return 0;
}