#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Tree.h"

int main()
{
    Sqstack s;
    Initstack(s);
    BiTree root = NULL;
    CreateTree(root);
    printf("先序遍历结果是: ");
    Preorder(root);
    printf("\n中序遍历结果是: ");
    Inorder(root);
    printf("\n后序遍历结果是: ");
    Postorder(root);
    printf("\n层序遍历结果是: ");
    Levelorder(root);
    printf("\n二叉树结点个数是%d\n", BiTNodeNum((root)));
    printf("二叉树的深度为%d\n", Depth((root)));
    printf("二叉树叶子结点的个数为%d\n", LeafNodeNum((root)));
    printf("二叉树度为1的结点个数为%d\n", Node1Num((root)));
    printf("二叉树度为2的结点个数为%d\n", Node2Num((root)));
    printf("打印根节点到叶子结点的路径\n");
    LeafPath(root, s);
    printf("左右孩子结点互换后先序遍历二叉树\n");
    swapchild(root);
    Preorder(root);    
    return 0;
}

void CreateTree(BiTree &T){
    char ch;
    scanf("%c", &ch);
    if(ch=='#'){
        T = NULL;            //注意置空
        return;
    }
    else{
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = ch;
        CreateTree(T->left);
        CreateTree(T->right);
    }

}

void Preorder(BiTree T){
    if(!T)
        return;
    else{
        printf("%c", T->data);
        Preorder(T->left);
        Preorder(T->right);
    }
}

void Inorder(BiTree T){
        if(!T)
        return;
    else{
        Inorder(T->left);
        printf("%c", T->data);
        Inorder(T->right);
    }
}        
void Postorder(BiTree T){
    if(!T)
        return;
    else{
        Postorder(T->left);
        Postorder(T->right);
        printf("%c", T->data);
    }
}

int Depth(BiTree T){
    if(!T)
        return 0;
    else{
        int depth_left = Depth(T->left);
        int depth_right = Depth(T->right);
        if (depth_left>depth_right)
            return (depth_left + 1);
        else
            return (depth_right + 1);
    }
}

int BiTNodeNum(BiTree T){
    if(!T)
        return 0;
    else{
        return (BiTNodeNum(T->left) + BiTNodeNum(T->right) + 1);
    }
}

int LeafNodeNum(BiTree T){
    if(!T)
        return 0;
    if(T->left==NULL&&T->right==NULL){
        return 1;
    }
    else
        return LeafNodeNum(T->left) + LeafNodeNum((T->right));
}

int Node1Num(BiTree T){
    if(!T)
        return 0;
    if(T->left==NULL&&T->right!=NULL){
        return Node1Num(T->right) + 1;
    }
    else if(T->left!=NULL&&T->right==NULL){
        return Node1Num(T->left) + 1;
    }
    else if(T->left!=NULL&&T->right!=NULL){
        return Node1Num(T->left) +  Node1Num(T->right);        
    }
    else
        return 0;
}

int Node2Num(BiTree T){
    if(!T)
        return 0;
    if(T->left!=NULL&&T->right!=NULL){
        return Node2Num(T->left) + Node2Num(T->right)+1;        
    }
    else if(T->left==NULL&&T->right!=NULL){
        return Node2Num(T->right) ;
    }
    else if(T->left!=NULL&&T->right==NULL){
        return Node2Num(T->left) ;
    }
    else
        return 0;
}

void Levelorder(BiTree T){
    if(!T)
        return ;
    int depth = Depth(T);
    for (int i = 1; i <= depth; i++)
    {
        _Levelroder(T, i);
    }
}

void _Levelroder(BiTree T,int depth){
    if(!T||depth==0)
        return;
    if(depth==1)
        printf("%c", T->data);
    _Levelroder(T->left, depth - 1);
    _Levelroder(T->right, depth - 1);
    return;
}

void LeafPath(BiTree T,Sqstack &s){
    Push(s, T->data);
    if(T==NULL)
        return;
    if(T->left==NULL&&T->right==NULL){
        printSqstack(s);
    }
    else{
        if(T->left!=NULL)
            LeafPath(T->left, s);
        if(T->right!=NULL)
            LeafPath(T->right, s);
    }
    char temp;
    Pop(s, temp);
    return;
}

bool swapchild(BiTree &T){
    BiTree temp;
    if(T){
        temp = T->left;
        T->left = T->right;
        T->right = temp;
        swapchild(T->left);
        swapchild(T->right);
     }
    return OK;
}

bool Initstack(Sqstack &s){
    s.base = (int *)malloc(sizeof(int) * MAXSIZE);
    if(!s.base)
        return ERROR;
    s.top = s.base;
    s.capacity = MAXSIZE;
    return OK;
}

bool Push(Sqstack &s, char e){
    if(s.top-s.base==s.capacity)
        return ERROR;
    *s.top++ = e;
    return OK;
}

bool Pop(Sqstack &s,char &e){
    if(s.top==s.base)
        return ERROR;
    s.top--;
    return OK;
}

void printSqstack(Sqstack s){    //从栈底开始打印，路径则为从根节点到叶子结点
    while(s.base!=s.top){
        printf("%c ", *s.base);
        s.base++;
    }
    printf("\n");
    return;               
}
