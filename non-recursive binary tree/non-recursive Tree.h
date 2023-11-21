#define OK  1
#define ERROR 0
#define MAXSIZE 100
#ifndef  _Tree_H

struct Sqstack;
typedef struct Sqstack stack;
struct BiTNode;
typedef struct BiTNode *Bitree;

void Create(Bitree &T);             //创建一颗二叉树
void preorder(Bitree T);            //先序遍历
void Levelorder(Bitree T);          //层序遍历
void Initstack(Sqstack &s);         //初始化顺序栈
bool Push(Sqstack &s, Bitree e);    //入栈
bool Pop(Sqstack &s, Bitree &e);    //出栈   e带回栈顶元素
bool Top(Sqstack s,Bitree &e);      //栈顶元素赋给e
bool IsEmptyStack(Sqstack s);       //判断栈是否为空
#endif  //_Tree_H

struct Sqstack{
    Bitree data[MAXSIZE];
    int tag[MAXSIZE];      
    int top;                          
};

struct BiTNode{
    char data;
    struct BiTNode *left;
    struct BiTNode *right;
};
