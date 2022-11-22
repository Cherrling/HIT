#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int order;
    struct node *next;
} NODE;
NODE *build(int n)
{
    NODE *head;
    NODE *prep;
    NODE *p = (NODE *)malloc(sizeof(NODE));
    head = p;
    prep = p;
    for (int i = 0; i < n - 1; i++)
    {
        p = (NODE *)malloc(sizeof(NODE));

        prep->next = p;
        prep = p;
    }
    prep->next = head;

    return head;
}

int main()
{
    printf("出圈成员及顺序：");
    NODE *head = build(13);
    NODE *tmp = head;
    NODE *prep = head;
    for (int i = 0; i < 13; i++)
    {

        tmp->order = i + 1;
        tmp = tmp->next;
    }
    tmp = head;
    for (int i = 0; i < 99999; i++)
    {
        int n;
        n = (i ? 3 : 2);

        for (int i = 0; i < n; i++)
        {
            prep = tmp;
            tmp = tmp->next;
        }

        prep->next = tmp->next;
        if (tmp->next == tmp)
        {
            break;
        }
        printf("%3d", tmp->order);
    }
    printf("\n最后的成员是：%3d",tmp->order);
}