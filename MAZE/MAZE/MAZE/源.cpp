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
int length = -1;                 //��ͼ��С
char bestname[10] = "Anonymous"; //��óɼ��û�����
char name[10] = "Anonymous";     //��ǰ�û���
float best = 0;                  //��ʷ��߷���
int node_size;                   //��������Ĵ�С
int *map = NULL;                 //�洢��ͼ������
int i, j;                        //��ҵ�ǰ������
int difficulty;                  //��ǰģʽ���Ѷ�
int trap[4][2];                  //������ɵ���������
int treasure[3][2];              //������ɵı�������
int win = 0;                     //���ʤ������
ExMessage m;                     // ������Ϣ����
struct data                      //�洢���ʤ�����ݵĵ����ṹ��
{
    int order;
    float time;
    int difficulty;
    float score;
};
typedef struct node //��������Ľṹ��ڵ�
{
    struct data data;
    struct node *next;
} NODE;

NODE *head = NULL; //�����ͷָ��

//��̬�������ڵ㣬���ڼ�¼�û�ʤ���������Ϣ
//����ʤ���Ĵ��������Ѷȣ�����ʱ��͵÷����
NODE *winadd(float time, float score)
{

    NODE *p;

    p = (NODE *)malloc(sizeof(NODE)); //�����ڴ�ռ�
    if (p == NULL)                    //δ����ɹ����˳���������
    {
        exit(0);
    }
    else
    {
        //��ͷָ��Ϊ�գ�����һ�δ�������ʱ����ͷָ�븳ֵ����¼�����Ϣ
        if (head == NULL)
        {
            head = p;
            p->data.order = 1;
            p->data.time = time;
            p->data.difficulty = difficulty;
            p->data.score = score;
            p->next = NULL;
        }
        else //��ͷָ�벻Ϊ�գ����ڶ��μ��Ժ��¼ʤ����Ϣʱ
        {
            NODE *t = head;
            int i = 2;
            for (; t->next != NULL;) //����������ĩ��
            {
                t = t->next;
                i++;
            }
            //������ĩ���½ڵ���и�ֵ
            p->data.order = i;
            p->data.time = time;
            p->data.difficulty = difficulty;
            p->data.score = score;
            t->next = p;
            p->next = NULL;
        }
    }

    return head; //����ͷָ��
}

//��������������Ҫ����ÿ��ʤ�����÷����ĸߵͽ�������
//����ð�����򷽷���ʹ�����ɸߵ�������
void chainsort(NODE *head)
{
    struct data tmp;
    if (head != NULL) //����ͷָ�벻Ϊ�գ������ٴ���һ��ʤ����Ϣʱ����ִ������
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

//���ڿ�ʼ��Ϸ���ڵĻ���
// ������ifname==1ʱ���ж���Ҫ��¼�û�����
int start(int ifname = 0)
{ //��մ�������
    cleardevice();

    // size����洢���ĸ��ѶȰ�ť����Ҫ���߼�����
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

    // leng����洢�������Ѷȶ�Ӧ�ĵ�ͼ�߳�
    int leng[4] = {7, 15, 31, 51};

    setlinecolor(BLACK);
    // �����������Ѷ�ѡ��
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
                 PROOF_QUALITY, DEFAULT_PITCH); // ����������ʽ
    outtextxy(180, 380, _T("��"));
    outtextxy(380, 380, _T("��ͨ"));
    outtextxy(580, 380, _T("����"));
    outtextxy(780, 380, _T("��ʦ"));

    // ������ifname==1ʱ���ж���Ҫ��¼�û�����
    if (ifname)
    {
        // ��¼�û�����������name�ַ�����
        InputBox(name, 10, "������������֣�", "MAZE",
                 "Anonymous", 0, 0, false);
    }

    // ����whileѭ�������������м��
    while (true)
    {

        // ��ȡһ�����򰴼���Ϣ
        m = getmessage(EX_MOUSE | EX_KEY);

        switch (m.message)
        {
            // ����⵽��굥��ʱ
        case WM_LBUTTONDOWN:
            // �����������б������ж��Ƿ����Ѷ�ѡ��
            for (int k = 0; k < 4; k++)
            {
                if (m.x >= size[k][0] &&
                    m.y >= size[k][1] &&
                    m.x <= size[k][2] &&
                    m.y <= size[k][3])
                {
                    // �û�����Ѷ�ѡ��󣬶���ز������и�ֵ
                    difficulty = k;
                    length = leng[k];
                    node_size = (int)(720.0 / (float)length);
                    return 0;
                }
            }
            // ����⵽��������ʱ
        case WM_KEYDOWN:
            // �ж��û�����Esc����������-1��ʾ�˳�����
            if (m.vkcode == VK_ESCAPE)
                return -1; // �� ESC ���˳�����
        }
    }
}

//�ж��Ƿ��ظ���������⵱ǰ�����Ƿ��ѱ�������move������
int dup(int move[4], int n)
{
    for (int i = 0; i < 4; i++)
    {
        // ȷ���ظ��򷵻�1�����򷵻�0
        if (move[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

// ���������������ÿ�ε���ʱ�����˳��������������ĸ�����ֱ��Ӧ0��1��2��3
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

// ���������ͼ�ĺ��ĺ�������Ҫ�����������˳����е�ͼ���������
// ʹ�õ����㷨�еݹ�������������
void genpath(int x, int y)
{
    // �����εõ�������ֵ�ڵ�ͼ�ϱ�Ϊ1
    *(map + x * length + y) = 1;

    // �����ƶ�˳�����飬������randdig�������������������˳��
    int move[4] = {-1, -1, -1, -1};
    randdig(move);

    // ��move������б���
    for (int k = 0; k < 4; k++)
    {
        if (move[k] == 0)
        {
            // ���ڴ��εõ�������ֵ�������Ӧ�����������δ�����Ϊ��·��
            //����δԽ�磬���Ǵ˷���Ϊͨ·��ͬʱ��Ǹ÷����м��Ϊͨ·
            if ((x - 2) > 0 && !*(map + (x - 2) * length + y))
            {
                *(map + (x - 1) * length + y) = 1;
                // if�ж��ɱ�ǵ�·�󣬲�����������㷨��ֱ�ӵ�������Ը÷�����еݹ����
                genpath(x - 2, y);
            }
        }
        // ���·���ͬ��
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

// ���õ�ͼ������ʹ��ͼ���������������з��鱻���Ϊ0
// ͬʱ����genpath�������е�ͼ���������
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

// ��������ƶ��������ȶ������һλ�������������������ٻ��ڵ�ǰ����ֵ������ҵ�ǰλ��
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

// �ƶ���������Ҫ�ж�����Ƿ�����Ӧ�����ƶ�
int move(char direction)

{
    switch (direction)
    {
    case 'w':
        // ��������ƶ�����Ϊͨ·��δԽ�磬�ж���������ƶ�
        // ���·���ͬ��
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

// ������ƺ�������Ҫ���������Թ�����Ļ���
void pout()
{
    // ʹ���������ƺ�������ֹһ���Ի��ƴ�������ʱ�����Ļ��˸
    BeginBatchDraw();
    cleardevice(); //��յ�ǰ��Ļ����

    // ����ѭ��������ͼ������λ��
    for (int x = 0; x < length; x++)
    {
        for (int y = 0; y < length; y++)
        {
            // ������ɫΪ��ɫ����ʽΪб�ߣ������Թ�Χǽ�Ļ���
            setfillcolor(BLACK);
            setfillstyle(BS_HATCHED, HS_BDIAGONAL);
            if (*(map + x * length + y) == 0)
            {

                fillrectangle(y * node_size,
                              x * node_size,
                              (y + 1) * node_size,
                              (x + 1) * node_size);
            }

            // ������ɫΪ��ɫ����ʽΪȫ��䣬���������Ļ���
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
            // ������ɫΪ��ɫ����ʽΪȫ��䣬���б��ؿ�Ļ���

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

    // ������Ļ��ʾ��Ϣ�Ļ���
    settextstyle(24, 0, "Consolas", 0, 0, 700, false, false, false,
                 DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                 CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH); // ����������ʽ
    settextcolor(BLACK);
    outtextxy(750, 0, _T("ʹ��Сдwasd�����ƶ�"));
    outtextxy(750, 25, _T("��rˢ�µ�ͼ"));
    outtextxy(750, 50, _T("��q�޸��Ѷ�"));
    outtextxy(750, 75, _T("��Esc�˳�"));

    setfillcolor(RED);
    fillroundrect(752, 102, 773, 123, 25 * 0.4, 25 * 0.4);
    outtextxy(780, 100, _T("Ϊ���壬����ʱ��ˢ�µ�ͼ"));

    setfillcolor(RGB(255, 215, 0));
    fillroundrect(752, 127, 773, 148, 25 * 0.4, 25 * 0.4);
    outtextxy(780, 125, _T("Ϊ���أ�����ʱ��10��"));

    // ��������ѻ�ʤ�����Ļ��ƣ���ʤ�����洢��win������
    outtextxy(750, 150, _T("��ʤ����:"));
    char number[12];
    char sen[200] = {};
    sprintf(number, "%d", win);
    outtextxy(880, 150, number);

    // ������ʷ��߷ֵĻ��ƣ���ʤ�����洢��best��bestname������
    outtextxy(750, 175, _T("��ʷ��߷�:"));
    outtextxy(880, 175, bestname);
    sprintf(number, "%.2f", best);
    outtextxy(1000, 175, number);

    // ������ҵ�����������а�����
    outtextxy(750, 200, _T("���а�"));

    chainsort(head); //���Ƚ������������ݵ�����

    // ������������ӡ���е�����
    // ������ʤʱ���Ѷȣ�����ʱ������÷���
    NODE *t = head;
    int num = 1;
    if (t != NULL)
    {
        while (1)
        {
            settextstyle(20, 0, "Consolas", 0, 0, 700, false, false, false,
                         DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
                         CLIP_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH); // ����������ʽ
            strcpy(sen, "");

            // strcat(sen, "��");

            // sprintf(number, "%d", t->data.order);
            // strcat(sen, number);

            // strcat(sen, "����Ϸ��");
            char diff[4][8] = {"��", "��ͨ", "����", "��ʦ"};
            strcat(sen, diff[t->data.difficulty]);

            strcat(sen, "�ѶȺ�ʱ");

            sprintf(number, "%.2f", t->data.time);
            strcat(sen, number);
            strcat(sen, "�룬�÷�");

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

// ��������������꺯��
// ���������Ѷȣ��ֱ����ֻ������0��1��2��3������
// ÿ���ж������Ƿ�����ĸ���Ϊ80%
void gentrap()
{
    int x, y;
    // ���������������
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
                // �����ж�����ֹ���������ڳ���ڴ�
                if ((x == 1 && y == 1) || (x == length - 1 && y == length - 1))
                {
                    continue;
                }
                // �����ж�����ֹ�������������е�����λ����
                for (int l = 0; l < 4; l++)
                {
                    if (x == trap[l][0] && y == trap[l][1])
                    {
                        continue;
                    }
                }
                // �����ж�����ֹ���������ڱ���λ����
                for (int l = 0; l < 4; l++)
                {
                    if (x == treasure[l][0] && y == treasure[l][1])
                    {
                        continue;
                    }
                }
                break;
            }
            // �ɹ����������������и�ֵ
            trap[k][0] = x;
            trap[k][1] = y;
        }
    }
}

// ������ɱ������꺯��
// ���ڼ��Ѷȣ�������1������
// ������ͨ�������Ѷȣ���30%��������2�����أ�70%��������3������
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
            // �����ж����������������ڳ���ڴ�
            if ((x == 1 && y == 1) || (x == length - 1 && y == length - 1))
            {
                continue;
            }
            // �����ж�����ֹ��������������λ����
            for (int l = 0; l < 4; l++)
            {
                if (x == trap[l][0] && y == trap[l][1])
                {
                    continue;
                }
            }
            // �����ж�����ֹ�������������еı���λ����
            for (int l = 0; l < 4; l++)
            {
                if (x == treasure[l][0] && y == treasure[l][1])
                {
                    continue;
                }
            }
            break;
        }
        // �ɹ����ɱ����������и�ֵ
        treasure[k][0] = x;
        treasure[k][1] = y;
    }
}

// ����ÿ�ŵ�ͼ���������һ��single_game����
int single_game()
{
    int st, et;          //��ʼ����ʼ������ʱ��
    int prei, prej;      //�洢�����һλ��
    float score = 0;     //�洢��ǰ�ִε÷֣���ʼֵΪ0
    st = GetTickCount(); //���ÿ�ʼʱ�䣬��λ����
    gentrap();           //���������������
    gentreasure();       //������ɱ�������
    pout();              //�����Թ���ͼ����ʾ��Ϣ�����а��
    pmove(i, j);         //��ʼ�������������

    // ʹ��while����������Ұ������ж�
    while (1)
    {

        m = getmessage(EX_CHAR); //������Ϣ����
        flushmessage();          //�����Ϣ������
                                 // �� ESC ���˳�����
        if (m.vkcode == VK_ESCAPE)
        {
            return -1;
        }
        //��r������ѭ��������single_game��������ʵ�ֵ�ͼ��ˢ��
        else if (m.ch == 'r')
        {
            break;
        }
        //��q��ʱ������start������ʹ�û�����ѡ���Ѷȣ�
        //�������û�ѡ����Ѷ����·���mapʹ�õ��ڴ�ռ䣬ʵ�ֶ�̬����
        else if (m.ch == 'q')
        {
            if (start() == -1)
            {
                return -1;
            }
            delete[] map;                   //�ͷ�ԭmap�����ڴ�
            map = new int[length * length]; //���·�����map��ͼ�ռ�
            break;
        }
        //�û�ʹ��wasd�����ƶ�ʱ
        else if (m.ch == 'w' || m.ch == 'a' || m.ch == 's' || m.ch == 'd')
        {
            // ��¼�û���ǰ����
            prei = i;
            prej = j;
            // �ж��û��Ƿ��ܳɹ��ƶ�
            if (move(m.ch))
            {
                // ������ƶ��������û�����λ��
                pmove(prei, prej);

                // ѭ�������û��Ƿ�ȵ�����
                for (int k = 0; k < 4; k++)
                {
                    //�ȵ�����ʱ���������ɵ�ͼ��ͬʱ���������µ��������꣬���ٴλ����û�λ��
                    if (i == trap[k][0] && j == trap[k][1])
                    {
                        resetmap();
                        gentrap();
                        pout();
                        pmove(i, j);
                    }
                }
                // ѭ�������û��Ƿ�ȵ�����
                for (int k = 0; k < 3; k++)
                {
                    //�ȵ�����ʱ���û��÷ּ�10��ͬʱ�����ǰ����
                    if (i == treasure[k][0] && j == treasure[k][1])
                    {
                        score += 10;
                        treasure[k][0] = 0;
                        treasure[k][1] = 0;
                    }
                }

                // �ж��û��Ƿ��ߵ�����
                if (i == length - 2 && j == length - 1)
                {
                    // �û��ߵ�����ʱ����¼����ʱ�䣬ͬʱʹ��ʤ������1
                    et = GetTickCount();
                    win++;
                    // ʹ�ú��������û��÷�
                    score += (float)((difficulty + 1) * (difficulty + 1) * 100 * 1000) / (float)(et - st);
                    // ����û��÷ִ�������߷ּ�¼���������߷ּ�¼
                    if (score >= best)
                    {
                        best = score;
                        strcpy(bestname, name);
                        FILE *fp = fopen("best.dat", "wb");
                        fprintf(fp, "%s %f", bestname, best);
                        fclose(fp);
                    }
                    // ʹ���������ڵ㣬��¼�û�ʤ����Ϣ
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
    // ���������ڣ������ñ�����ɫ
    initgraph(1080, 720);
    setbkcolor(RGB(255, 248, 220));
    PlaySound(TEXT("bk.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    // ����start�������ƿ�ʼ���棬����û���Esc�����������
    if (start(1) == -1)
    {
        return 0;
    }

    // �ļ����������Զ�ȡ��߷ִ浵
    FILE *fp = fopen("best.dat", "rb");
    if (fp != NULL)
    {
        // �����ȡ���浵����ȡ�浵�е������ͷ�����bestname��best������
        fscanf(fp, "%s %f", bestname, &best);
        fclose(fp);
    }
    else
    {
        // ���δ��ȡ���浵�����½��浵�������ʼֵ
        FILE *fp = fopen("best.dat", "wb");
        fprintf(fp, "%s %f", "Anonymous", 0);
        fclose(fp);
    }

    // ��¼��ǰ�浵�е���߷�
    float prebest = best;

    // ʹ�ö�̬���鴴��map���飬���ڵ�ͼ�Ĵ��
    map = new int[length * length];

    // ʹ��ʱ��ֵ��Ϊ���������
    srand(GetTickCount());

    // ʹ��ѭ���ظ�������Ϸ
    // ��single_game��������-1ʱ���ж��û��˳������˳�����
    while (1)
    {
        // ���õ�ͼ����
        resetmap();
        // �����������
        i = 1, j = 0;
        // ���뵥����Ϸ
        if (single_game() == -1)
        {
            break;
        }
    }

    // �û��˳�ʱ�������ǰ���������֮ǰ��߷ּ�¼��������߷�д��浵��
    if (best > prebest)
    {
        FILE *fp = fopen("best.dat", "wb");
        fprintf(fp, "%s %f", bestname, best);
        fclose(fp);
    }
    // �ͷŵ�ͼռ�õ��ڴ�ռ�
    free(map);
    return 0;
}