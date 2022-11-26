#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <graphics.h>
int length = -1;
int node_size;
int *map=NULL;
int i,j;
int trap[4][2];

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
            for (int k = 0; k < 4; k++)
            {
                if (m.x >= size[k][0] && m.y >= size[k][1] && m.x <= size[k][2] && m.y <= size[k][3])
                {
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
int randdig(int move[4])
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

void genpath(int *map, int x, int y)

{

    *(map + x * length + y) = 1;
    int move[4] = {-1, -1, -1, -1};
    randdig(move);
    for (int k = 0; k < 4; k++)
    {
        if (move[k] == 0)
        {
            if ((x - 2) > 0 && !*(map + (x - 2) * length + y))
            {
                *(map + (x - 1) * length + y) = 1, genpath(map, x - 2, y);
            }
        }
        if (move[k] == 1)
        {
            if ((x + 2) < length && !*(map + (x + 2) * length + y))
            {
                *(map + (x + 1) * length + y) = 1, genpath(map, x + 2, y);
            }
        }
        if (move[k] == 2)
        {
            if ((y - 2) > 0 && !*(map + (x)*length + y - 2))
            {
                *(map + (x)*length + y - 1) = 1, genpath(map, x, y - 2);
            }
        }
        if (move[k] == 3)
        {
            if ((y + 2) < length && !*(map + (x)*length + y + 2))
            {
                *(map + (x)*length + y + 1) = 1, genpath(map, x, y + 2);
            }
        }
    }
}
int pmove(int prei, int prej)
{
    clearrectangle(prej * node_size, prei * node_size, (prej + 1) * node_size, (prei + 1) * node_size);
    roundrect(j * node_size + node_size * 0.1, i * node_size + node_size * 0.1, (j + 1) * node_size - node_size * 0.1, (i + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
}
int pout(int *map, int i, int j, int win, NODE *head)
{
    cleardevice();
    BeginBatchDraw();
    for (int x = 0; x < length; x++)
    {
        for (int y = 0; y < length; y++)
        {
            if (*(map + x * length + y) == 0)
            {
                // _cputs("[]");

                fillroundrect(y * node_size + node_size * 0.1, x * node_size + node_size * 0.1, (y + 1) * node_size - node_size * 0.1, (x + 1) * node_size - node_size * 0.1, (float)node_size * 0.4, (float)node_size * 0.4);
            }
        }
    }
    EndBatchDraw();

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

int gentrap(int diff){

}

int single_game(int win, NODE *head)
{
    int st, et;
    int prei, prej;
    st = time(NULL);
    pout(map, i, j, win, head);
    pmove( i, j);
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
            printf("%d",length);
            delete [] map;
            map=new int [length*length];
            break;
        }
        else if (m.ch == 'w' || m.ch == 'a' || m.ch == 's' || m.ch == 'd')
        {
            prei = i;
            prej = j;
            if (move(m.ch))
            {
                if (i == length - 2 && j == length - 1)
                {
                    et = time(NULL);
                    win++;
                    head = winadd(head, (et - st));
                    break;
                }
                pmove(prei, prej);
            }
        }
    }
    return 0;
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
    map=new int [length*length];
    // map = (int *)malloc(sizeof(int) * 51 * 51);

    while (1)
    {
        for (int k = 0; k < length * length; k++)   
        {
            *(map + k) = 0;
        }
        srand(rand());
        genpath(map, 1, 1);
        i = 1, j = 0;
        *(map + 1 * length + 0) = 1;
        *(map + (length - 2) * length + length - 1) = 1;
        if (single_game(win, head) == -1)
        {
            break;
        }
    }
    free(map);
}