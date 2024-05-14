#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// tag 是结构体标签。

// member-list 是标准的变量定义，比如 int i; 或者 float f;，或者其他有效的变量定义。

// variable-list 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。
// struct tag { 
//     member-list
//     member-list 
//     member-list  
//     ...
// } variable-list ;



//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//同时又声明了结构体变量s1
//这个结构体并没有标明其标签
struct 
{
    int a;
    char b;
    double c;
} s1;
 
//此声明声明了拥有3个成员的结构体，分别为整型的a，字符型的b和双精度的c
//结构体的标签被命名为SIMPLE,没有声明变量
struct SIMPLE
{
    int a;
    char b;
    double c;
};
//用SIMPLE标签的结构体，另外声明了变量t1、t2、t3
struct SIMPLE t1, t2[20], *t3;
 
//也可以用typedef创建新类型
typedef struct
{
    int a;
    char b;
    double c; 
} Simple2;
//现在可以用Simple2作为类型声明新的结构体变量
Simple2 u1, u2[20], *u3;



// C 语言提供了 typedef 关键字，您可以使用它来为类型取一个新的名字。下面的实例为单字节数字定义了一个术语 BYTE：

    typedef unsigned char BYTE;
//  1       2               3

struct SIMPLE
{
    int a;
    char b;
    double c;
};

// struct SIMPLE s1;

// s1.a=10;
// printf("%d",s1.a);





typedef struct list
{
    int adj;
    struct list *next;
} LIST;

//此结构体的声明包含了其他的结构体
struct COMPLEX
{
    char string[100];
    struct SIMPLE a;
};
 
//此结构体的声明包含了指向自己类型的指针
struct NODE
{
    char string[100];
    struct NODE *next_node;
};



int main()
{
    LIST *head;
    head = Build();
    print(head);
}