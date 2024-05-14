#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list
{
    int adj;
    struct list *next;
} LIST;

LIST *Build()
{

    LIST *prePt, *Pt, *head;

    for (int i = 0; i < 6; i++)
    {
        Pt = (LIST *)malloc(sizeof(LIST));
        if (Pt == NULL)
        {
            exit(0);
        }
        else
        {
            if (!i)
            {
                head = Pt;
            }
            else
            {
                prePt->next = Pt;
                Pt->next = NULL;
            }
            prePt = Pt;
            scanf("%d", &(Pt->adj));
        }
    }
    return head;
}

void print(LIST *head)
{
    // LIST *p = head;
    // for (int i = 0; i < 6; i++)
    // {
    //     printf("%d ", p->adj);
    //     p = p->next;
    // }


    LIST *p = head;
    for (;;)
    {
        printf("%d ", p->adj);
        if (p->next==NULL)
        {
            return 0;
        }
        else
        {
            p = p->next;
        }
    }
}
int main()
{
    LIST *head;
    head = Build();
    print(head);
}