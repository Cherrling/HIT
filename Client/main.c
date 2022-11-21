#include <stdio.h>
#include <string.h>
#define M 40
#define N 12
typedef struct record
{
    char name[N];
    char address[N];
    int times;

} CLIENT;
void Input(CLIENT client[N], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Input name for client %d\n", i + 1);
        scanf("%s", client[i].name);
        printf("Input address for client %d\n", i + 1);
        scanf("%s", client[i].address);
        printf("Input times for client %d\n", i + 1);
        scanf("%d", &(client[i].times));
    }
}
void Sort(CLIENT client[N], int n)
{
    CLIENT tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (client[j + 1].times < client[j].times)
            {
                tmp = client[j];
                client[j] = client[j + 1];
                client[j + 1] = tmp;
            }
        }
    }
}
void Search(CLIENT client[N], int n, int count)
{
    int found = -1;
    for (int i = 0; i < n; i++)
    {
        if (client[i].times >= count)
        {
            found = i;
            break;
        }
    }
    if (found == -1)
    {
        printf("Not found!\n");
    }
    else
    {
        CLIENT tmp;
        for (int i = found; i < n; i++)
        {
            for (int j = found; j < n - 1; j++)
            {
                if (strcmp(client[j + 1].name, client[j].name) < 0)
                {
                    tmp = client[j];
                    client[j] = client[j + 1];
                    client[j + 1] = tmp;
                }
            }
        }
        for (int i = found; i < n; i++)
        {
            printf("Client name: %s\n", client[i].name);
            printf("Client address: %s\n", client[i].address);
            printf("Client times %d\n", client[i].times);
        }
    }
}
int main()
{
    CLIENT client[M];
    int n, times;
    printf("Input n:");
    scanf("%d", &n);
    Input(client, n);
    printf("Input minimal times:");
    scanf("%d", &times);
    Sort(client, n);
    Search(client, n, times);
    return 0;
}