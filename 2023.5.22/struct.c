#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// tag �ǽṹ���ǩ��

// member-list �Ǳ�׼�ı������壬���� int i; ���� float f;������������Ч�ı������塣

// variable-list �ṹ�����������ڽṹ��ĩβ�����һ���ֺ�֮ǰ��������ָ��һ�������ṹ������
// struct tag { 
//     member-list
//     member-list 
//     member-list  
//     ...
// } variable-list ;



//������������ӵ��3����Ա�Ľṹ�壬�ֱ�Ϊ���͵�a���ַ��͵�b��˫���ȵ�c
//ͬʱ�������˽ṹ�����s1
//����ṹ�岢û�б������ǩ
struct 
{
    int a;
    char b;
    double c;
} s1;
 
//������������ӵ��3����Ա�Ľṹ�壬�ֱ�Ϊ���͵�a���ַ��͵�b��˫���ȵ�c
//�ṹ��ı�ǩ������ΪSIMPLE,û����������
struct SIMPLE
{
    int a;
    char b;
    double c;
};
//��SIMPLE��ǩ�Ľṹ�壬���������˱���t1��t2��t3
struct SIMPLE t1, t2[20], *t3;
 
//Ҳ������typedef����������
typedef struct
{
    int a;
    char b;
    double c; 
} Simple2;
//���ڿ�����Simple2��Ϊ���������µĽṹ�����
Simple2 u1, u2[20], *u3;



// C �����ṩ�� typedef �ؼ��֣�������ʹ������Ϊ����ȡһ���µ����֡������ʵ��Ϊ���ֽ����ֶ�����һ������ BYTE��

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

//�˽ṹ������������������Ľṹ��
struct COMPLEX
{
    char string[100];
    struct SIMPLE a;
};
 
//�˽ṹ�������������ָ���Լ����͵�ָ��
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