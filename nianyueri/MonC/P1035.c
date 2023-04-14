#include <stdio.h>

int main()
{
    int k;
    double s = 0;
    scanf("%d", &k);
    for (int n = 1; n < 999999; n++)
    {
        // s = s + 1.0 / n;
        s += 1.0 / n;

        if (s > k)
        {
            printf("%d", n);
            return 0;
        }
    }
}
