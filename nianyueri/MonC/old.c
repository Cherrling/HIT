
#include <stdio.h>
int main()
{
    int i;
    int children = 12, mother = 36;
    for (i = 0; children*2 != mother; children++, mother++)
        i += 1;
    printf("year=%d\n" "mingAge=%d\n" "motherAge=%d\n",i, children,mother);
}