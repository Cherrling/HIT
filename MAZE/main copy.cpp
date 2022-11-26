#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>
int length = -1;
int node_size;

ExMessage m; // 定义消息变量
typedef struct node
{
    int order;
    int time;
    struct node *next;
} NODE;

NODE *winadd(NODE *head, int time)
{

    NODE *p;

    p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
    {
        exit(0);
    }
    else
    {
        if (head == NULL)
        {
            head = p;
            p->order = 1;
            p->time = time;
            p->next = NULL;
        }
        else
        {
            NODE *t = head;
            int i = 2;
            for (; t->next != NULL;)
            {
                t = t->next;
                i++;
            }
            p->order = i;
            p->time = time;

            t->next = p;
            p->next = NULL;
        }
    }

    return head;
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
    int leng[4] = {7, 15, 31, 51};
    for (int i = 0; i < 4; i++)
    {
        roundrect(size[i][0], size[i][1], size[i][2], size[i][3], 10, 10);
    }

    while (true)
    {

        // 获取一条鼠标或按键消息
        m = getmessage(EX_MOUSE | EX_KEY);

        switch (m.message)
        {
        case WM_LBUTTONDOWN:
            for (int i = 0; i < 4; i++)
            {
                if (m.x >= size[i][0] && m.y >= size[i][1] && m.x <= size[i][2] && m.y <= size[i][3])
                {
                    length = leng[i];
                    return 0;
                }
            }
        case WM_KEYDOWN:
            if (m.vkcode == VK_ESCAPE)
                return -1; // 按 ESC 键退出程序
        }
    }
    node_size = 720.0 / (float)length;
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
int randmove(int move[4])
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

void genpath(int *map, int i, int j)
{

    *(map + i * length + j) = 1;
    int move[4] = {-1, -1, -1, -1};
    randmove(move);
    for (int k = 0; k < 4; k++)
    {
        if (move[k] == 0)
        {
            if ((i - 2) > 0 && !*(map + (i - 2) * length + j))
            {
                *(map + (i - 1) * length + j) = 1, genpath(map, i - 2, j);
            }
        }
        if (move[k] == 1)
        {
            if ((i + 2) < length && !*(map + (i + 2) * length + j))
            {
                *(map + (i + 1) * length + j) = 1, genpath(map, i + 2, j);
            }
        }
        if (move[k] == 2)
        {
            if ((j - 2) > 0 && !*(map + (i)*length + j - 2))
            {
                *(map + (i)*length + j - 1) = 1, genpath(map, i, j - 2);
            }
        }
        if (move[k] == 3)
        {
            if ((j + 2) < length && !*(map + (i)*length + j + 2))
            {
                *(map + (i)*length + j + 1) = 1, genpath(map, i, j + 2);
            }
        }
    }
}
int pout(int *map, int i, int j, int win, NODE *head)
{
    cleardevice();
    // BeginBatchDraw();
    for (int x = 0; x < length; x++)
    {
        for (int y = 0; y < length; y++)
        {
            if (x == i && y == j)
            {
                // _cputs("<>");

                roundrect(y * node_size + node_size * 0.1, x * node_size + node_size * 0.1, (y + 1) * node_size - node_size * 0.1, (x + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
            }
            else if (*(map + x * length + y) == 0)
            {
                // _cputs("[]");

                fillroundrect(y * node_size + node_size * 0.1, x * node_size + node_size * 0.1, (y + 1) * node_size - node_size * 0.1, (x + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
            }
            else
            {
                // _cputs("  ");
            }
        }
    }
    // EndBatchDraw();

    // printf("使用小写wasd进行移动\n");
    // printf("按r刷新地图\n");
    // printf("按q修改地图大小\n");
    // printf("按Esc退出\n");
    // printf("获胜次数: %d\n", win);
    NODE *t = head;
    if (t != NULL)
    {
        while (1)
        {

            // printf("第%d次胜利耗时%d秒\n", t->order, t->time);
            if (t->next == NULL)
            {
                break;
            }
            t = t->next;
        }
    }
}

int pmove(int *map, int prei, int prej, int i, int j)
{
    clearrectangle(prej * node_size, prei * node_size, (prej + 1) * node_size, (prei + 1) * node_size);
    fillroundrect(j * node_size + node_size * 0.1, i * node_size + node_size * 0.1, (j + 1) * node_size - node_size * 0.1, (i + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
}
int move(int *map, int *i, int *j, char direction)
{
}

int main()
{
    initgraph(1080, 720);
    if (setsize() == -1)
    {
        return 0;
    }

    int win = 0;
    NODE *head = NULL;
    int *map;
    map = (int *)malloc(sizeof(int) * length * length);

    // while (1)
    // {
        for (int i = 0; i < length * length; i++)
        {
            *(map + i) = 0;
        }
        srand(rand());
        int i = 1, j = 0;
        genpath(map, 1, 1);
        *(map + 1 * length + 0) = 1;
        *(map + (length - 2) * length + length - 1) = 1;
        int st, et;
        int prei, prej;
        st = time(NULL);
        pout(map, i, j, win, head);

        // while (1)
        // {
        //     m = getmessage(EX_CHAR | EX_KEY);
        //     flushmessage();
        //     if (m.vkcode == VK_ESCAPE)
        //     {
        //         return -1; // 按 ESC 键退出程序
        //     }
        //     else if (m.ch == 'r')
        //     {
        //         printf("r\n");
        //         break;
        //     }
        //     else if (m.ch == 'q')
        //     {
        //         if (setsize() == -1)
        //         {
        //             return -1;
        //         }
        //         free(map);
        //         map = (int *)malloc(sizeof(int) * length * length);
        //         break;
        //     }
        //     else if ((m.ch == 'w' || m.ch == 'a' || m.ch == 's' || m.ch == 'd'))
        //     {
        //         switch (m.ch)
        //         {
        //         case 'w':
        //             if (*(map + (i - 1) * length + j) && i - 1 >= 0)
        //             {
        //                 i--;
        //             }
        //             return 1;
        //         case 'a':
        //             if (*(map + (i) * length + j - 1) && j - 1 >= 0)
        //             {
        //                 j--;
        //             }
        //             return 1;
        //         case 's':
        //             if (*(map + (i + 1) * length + j) && i + 1 < length)
        //             {
        //                 i++;
        //             }
        //             return 1;
        //         case 'd':
        //             if (*(map + (i) * length + j + 1) && j + 1 < length)
        //             {
        //                 j++;
        //             }
        //             return 1;
        //         default:
        //             return 0;
        //         }
        //         prei = i;
        //         prej = j;
        //         if (move(map, &i, &j, m.ch))
        //         {
        //             if (i == length - 2 && j == length - 1)
        //             {
        //                 et = time(NULL);
        //                 win++;
        //                 head = winadd(head, (et - st));
        //                 break;
        //             }
        //             pmove(map, prei, prej, i, j);
        //         }
        //     }
        // }
        // if (single_game(i, j, map, win, head) == -1)
        // {
        //     return 0;
        // }
    // }
    free(map);
}