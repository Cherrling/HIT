#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
int length = -1;
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
    // SetConsoleCursorInfo(GetStdHandle((DWORD)-311), &(CONSOLE_CURSOR_INFO){25});

    // SetConsoleCursorPosition(GetStdHandle((DWORD)-11), (COORD){0});

    for (int x = 0; x < length; x++)
    {

        for (int y = 0; y < length; y++)
        {
            if (x == i && y == j)
            {
                // _cputs("<>");
                SetConsoleTextAttribute(GetStdHandle((DWORD)-11), 79);
                printf("  ");
            }
            else if (*(map + x * length + y) == 0)
            {
                // _cputs("[]");
                // SetConsoleTextAttribute(GetStdHandle((DWORD)-11), 128);
                SetConsoleTextAttribute(GetStdHandle((DWORD)-11), 7);
                printf("[]");
            }
            else
            {
                // _cputs("  ");
                SetConsoleTextAttribute(GetStdHandle((DWORD)-11), 0);
                printf("  ");
            }
        }
        SetConsoleTextAttribute(GetStdHandle((DWORD)-11), 0);
        printf("\n");
    }
    SetConsoleTextAttribute(GetStdHandle((DWORD)-11), 15);

    printf("使用小写wasd进行移动\n");
    printf("按r刷新地图\n");
    printf("按q修改地图大小\n");
    printf("按Esc退出\n");
    printf("获胜次数: %d\n", win);
    NODE *t = head;
    if (t != NULL)
    {
        while (1)
        {

            printf("第%d次胜利耗时%d秒\n", t->order, t->time);
            if (t->next == NULL)
            {
                break;
            }
            t = t->next;
        }
    }
}
int setsize()
{
    system("cls");
    while (1)
    {
        printf("请输入期望的迷宫大小(仅限奇数)\n");
        printf("按0退出\n");
        scanf("%d", &length);
        if (length == 0)
        {
            return 0;
        }
        else if (length < 5)
        {
            printf("迷宫太小了\n");
        }
        else
        {
            if (length % 2 == 0)
            {
                length++;
            }
            system("cls");
            break;
        }
    }
}

int main()
{
    setsize();
    // system("mode con cols=%d lines=%d",length*2+1,length+10);

    int win = 0;
    int st, et;
    NODE *head = NULL;
    int *map;
    map = (int *)malloc(sizeof(int) * length * length);

    while (1)
    {
        for (int i = 0; i < length * length; i++)
        {
            *(map + i) = 0;
        }
        srand(rand());
        int ch = 0;
        int i = 1, j = 0;
        st = time(NULL);
        genpath(map, 1, 1);
        *(map + 1 * length + 0) = 1;
        *(map + (length - 2) * length + length - 1) = 1;

        pout(map, i, j, win, head);
        for (;;)
        {
            ch = _getch();
            if (ch == 27)
            {
                return 0;
            }
            else if (ch == 'r')
            {
                break;
            }
            else if (ch == 'q')
            {
                setsize();
                free(map);
                map = (int *)malloc(sizeof(int) * length * length);

                break;
            }
            else
            {
                switch (ch)
                {
                case 'w':
                    if (*(map + (i - 1) * length + j) && i - 1 >= 0)
                    {
                        i--;
                    }
                    break;
                case 'a':
                    if (*(map + (i)*length + j - 1) && j - 1 >= 0)
                    {
                        j--;
                    }
                    break;
                case 's':
                    if (*(map + (i + 1) * length + j) && i + 1 < length)
                    {
                        i++;
                    }
                    break;
                case 'd':
                    if (*(map + (i)*length + j + 1) && j + 1 < length)
                    {
                        j++;
                    }
                    break;
                default:
                    break;
                }
                pout(map, i, j, win, head);
                if (i == length - 2 && j == length - 1)
                {
                    et = time(NULL);
                    win++;
                    head = winadd(head, (et - st));
                    break;
                }
            }
        }
    }
    free(map);
}