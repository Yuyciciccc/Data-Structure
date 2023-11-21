#define OK 1
#define ERROR 0 
#define MAXSIZE 100

#ifndef _Tree_H
struct BiTNode;
typedef struct BiTNode BiTNode;
typedef BiTNode *BiTree;
struct stack;
typedef struct stack Sqstack;

void CreateTree(BiTree &T);        //创建空树
void Preorder(BiTree T);          //先序遍历
void Inorder(BiTree T);          //中序遍历
void Postorder(BiTree T);       //后序遍历
void Levelorder(BiTree T);      //层序遍历
void _Levelroder(BiTree T,int depth);     //扫描下一层
int Depth(BiTree T);           //返回树的深度
int BiTNodeNum(BiTree T);     //返回树结点的个数
int LeafNodeNum(BiTree T);    //返回叶子结点的个数
int Node1Num(BiTree T);      //返回度为1结点的个数
int Node2Num(BiTree T);      //返回度为2结点的个数
void LeafPath(BiTree T, Sqstack &s);     //打印根节点到叶子结点的路径
bool swapchild(BiTree &T);              //交换所有结点的左右孩子
bool Initstack(Sqstack &s);     //初始化栈
bool Push(Sqstack &s, char e);   //入栈
bool Pop(Sqstack &s,char &e);    //出栈
void printSqstack(Sqstack s);   //打印栈

#endif //_Tree_H

struct BiTNode{
    int data;
    BiTree left;
    BiTree right;
};

struct stack{
    int *top;
    int *base;
    int capacity;
};