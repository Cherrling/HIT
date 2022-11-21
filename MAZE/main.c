#include <conio.h>
#include <windows.h>
#define L 51
int map[L][L]={0};


void dig(int v)
{
    int a[4] = {2, -2, 2 * L, -2 * L}, i = 0, j;
    for (; j = rand() % 4, i < 4; i++)
        i - j && (a[i] ^= a[j] ^= a[i] ^= a[j]);
    for (map[v] = 1, i = 0; i < 4; i++)
    {
        if (v + a[i] < 0 || L * L < v + a[i] || map[v + a[i]])
            continue;
        if ((a[i] == 2 || a[i] == -2) && v / L - (a[i] + v) / L)
            continue;
        map[v + a[i] / 2] = 1, dig(v + a[i]);
    }
}