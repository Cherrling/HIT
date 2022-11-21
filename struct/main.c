#include <stdio.h>
#include <stdlib.h>
typedef struct num
{
    int a;
    struct num *next;
} NUM;
NUM *Build(int n, int b[6])
{
    NUM *Pt, *prePt, *head;
    Pt = (NUM *)malloc(sizeof(NUM));
    if (Pt != NULL)
    {
        Pt->a = b[0];
        head = Pt;
        prePt = Pt;
    }
    else
    {
        printf("Failed.\n");
        exit(0);
    }

    for (int i = 1; i < n; i++)
    {
        Pt = (NUM *)malloc(sizeof(NUM));
        if (Pt != NULL)
        {
            Pt->a = b[i];
            prePt->next = Pt;
            prePt = Pt;
        }
        else
        {
            printf("Failed.\n");
            exit(0);
        }
        Pt->next = NULL;
    }
    return head;
}
void printList(int n, NUM *head)
{
    NUM *prePt = NULL;
    NUM *Pt = head;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", Pt->a);
        prePt = Pt;
        Pt = prePt->next;
    }
}
int main()
{
    int b[6];
    int n = 6;
    NUM *head;
    printf("输入数组6个元素的值。\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    head = Build(n, b);
    printf("此链表各个结点的数据域为：");
    printList(n, head);
    return 0;
}
