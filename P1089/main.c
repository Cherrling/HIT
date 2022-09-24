#include <stdio.h>
// int main()
// {
//     int b = 0, c = 0, d = 0, e = 0, f = 0;
//     int a[12], g[12];
//     for (b = 0; b < 12; b++)
//     {
//         scanf("%d", &a[b]);
//         g[b] = 300 - a[b] + e;
//         if (g[b] >= 100)
//         {
//             d = (g[b] / 100) + d;
//             e = g[b] - 100 * (g[b] / 100);
//         }
//         else if (g[b] >= 0)
//         {
//             e = g[b];
//         }
//         else
//         {
//             printf("%d", -(b + 1));
//             return 0;
//         }
//     }
//     printf("%d", 120 * d + e);
//     return 0;
// }

int main()
{
    int month[12];
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &month[i]);
    }

    int num = 0, host = 0;
    for (int i = 0; i < 12; i++)
    {
        num += 300;
        if (num < month[i])
        {
            printf("%d", (-(i + 1)));
            return 0;
        }
        else if (num - month[i] >= 100)
        {
            int a = (num - month[i]) % 100;
            host += num - month[i] - a;
            num = a;
        }
        else
        {
            num -= month[i];
        }
    }
    printf("%d", (int)(num + host * 1.2));
    return 0;
}



