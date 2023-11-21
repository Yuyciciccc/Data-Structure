#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "non-recursive Tree.h"

int main()
{
    Bitree root;
    Create(root);
    preorder(root);
    return 0;
}

void Create(Bitree &T){
    Sqstack s;
    Sqstack *st = &s;
    Bitree temp;
    Bitree p1, p2;
    char ch[MAXSIZE];
    int i = 0;
    Initstack(s);
    scanf("%s", ch);
    while(ch[i]!='\0'){
        if(i==0){             //建立根节点
            T = (Bitree)malloc(sizeof(BiTNode));
            T->data = ch[i];
            T->left = NULL;            //左右子树均置空，后续所有新结点都需置空左右子树  
            T->right = NULL; 
            p1 = T; 
            Push(s, p1);               //注意先Push再赋值
            st->tag[st->top-1] = 0;        
        }
        else {
            if(ch[i]!='#'&&st->tag[st->top-1]==0){      //建立左子树
                p2=(Bitree)malloc(sizeof(BiTNode));     //tag为0则意味左子树未建立
                p2->data = ch[i];
                p2->left = NULL;
                p2->right = NULL;
                Push(s, p2);   
                p1->left = p2;
                p1 = p2;
                st->tag[st->top - 1] = 0;                 //继续创建该结点的左右子树
            }
            else if(ch[i]=='#'&&st->tag[st->top-1]==0){     //左子树创建完毕
                p1->left = NULL;                                
                st->tag[st->top - 1] = 1;
            }
            else if(ch[i]!='#'&&st->tag[st->top-1]==1){      //建立右子树
                p2=(Bitree)malloc(sizeof(BiTNode));          //tag为1则意味着左子树已建立右子树未建立 
                p2->data = ch[i];                            //这个create函数采取先序创建
                p2->left = NULL;
                p2->right = NULL;
                Push(s, p2);
                p1->right = p2;
                p1 = p2;
                st->tag[st->top - 1] = 0;              
            }
            else if(ch[i]=='#'&&st->tag[st->top-1]==1){      //右子树创建完成
                p1->right=NULL;
                st->tag[st->top - 1] = 2;                   //tag为0则该结点的左右子树均创建完毕
            }
        } 
        while(st->tag[st->top-1]==2){
            st->tag[st->top - 1] = 0;                       //栈顶清空元素，即准备回溯到上一个结点
            Pop(s, p1);                                     //回溯上一结点
            if(st->top!=0)  Top(s,p1);                      //除非回溯前结点为根节点，否则回溯到上一结点
            else
                break;
            if(st->tag[st->top-1]==1){                      //若该结点左子树已创建完毕，则回溯前结点为它的左右孩子，此时左右孩子均创建完毕
                st->tag[st->top - 1] = 2;
            }

        }
        if(st->tag[st->top-1]==1||p1->left!=NULL){          //若回溯结点
            st->tag[st->top - 1] = 1;
        }
    i++;
    }

}

void Levelorder(Bitree T){
    Sqstack s;
    Initstack(s);
    if(T!=NULL)
        Push(s, T);
    while(!T){
        if(T->left!=NULL)
            Push(s, T->left);
        if(T->right!=NULL)
            Push(s, T->right);
        printf("%c", T->data);
        T = T->left;
    }
    
}

void Initstack(Sqstack &s){
    s.top = 0;
}

bool Push(Sqstack &s,Bitree e){
    if(s.top+1==MAXSIZE)
        return ERROR;
    s.data[s.top++] = e;
    return OK;
}

bool Pop(Sqstack &s,Bitree &e){
    if(s.top==0)
        return ERROR;
    e = s.data[--s.top];
    return OK;
}

bool Top(Sqstack s,Bitree &e){
    if(s.top==0)
        return ERROR;
    e = s.data[s.top-1];
    return OK;
}