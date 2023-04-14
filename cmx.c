#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//     unsigned int a, y, m, d, i;
//     char ch;
//     printf("Please input your busiest day.\n");
//     if (scanf("%d", &a))
//         a = a * 2;
//     else
//     {
//         printf("Invalid input.");
//         return 0;
//     }
//     printf("Please input your gender.\n");
//     scanf(" %c", &ch);
//     if (ch == 'm')
//         a = a + 4;
//     else if (ch == 'f')
//         a = a + 8;
//     else
//     {
//         printf("Invalid input.");
//         return 0;
//     }
//     a = a * 50;
//     printf("Please input your birthday.\n");
//     scanf("%4d-%2d-%2d", &y, &m, &d);
//     i = scanf("%4d-%2d-%2d", &y, &m, &d);
//     if (i < 3)
//     {
//         printf("Invalid input.");
//         return 0;
//     }
//     else
//     {
//         if ((y % 4 == 0 && y % 100) || (y % 400 == 0))
//         {
//             if (m == 2 && d == 29)
//             {
//                 printf("Invalid input.");
//                 return 0;
//             }

//             if ((m > 0) && (m < 7))
//             {
//                 a = a + 2002;
//             }
//             if ((m > 6) && (m < 13))
//             {
//                 a = a + 3002;
//             }
//             else
//             {
//                 printf("Invalid input.");
//                 return 0;
//             }
//         }
//     }
//     a = a - y;
//     a = (a % 100) + 10;
//     printf("Your age is:%d\n", a);

//     return 0;
// }
// int main()
// {
//     char ch,c;
//     scanf("%c",&ch);
//     int i;
//     int a[26]={0};
//     while((c=getchar())!='\n')
//     {
//         for(i=0;i<27;i++)
//         {
//             if(c=='a'+i)
//                 {
//                     a[i]++;
//                 }
//         }

//     }

//     for(i=0;i<26;i++)
//     {
//         if(a[i]!=0)
//             {
//                 printf("%c=%d\n",i+'a',a[i]);
//             }
//     }

//     return 0;
// }
