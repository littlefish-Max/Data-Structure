//非递归的一个后序遍历二叉树
#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    char data;
    struct TreeNode *lchild,*rchild;
    int tag;
}TreeNode,*Tree;
void creattree(Tree &t)
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(TreeNode *)malloc(sizeof(TreeNode));
        t->data=ch;
        t->tag=0;
        t->lchild=NULL;
        t->rchild=NULL;
        creattree(t->lchild);
        creattree(t->rchild);
    }
}
void back(Tree t)
{
    struct TreeNode *stack[100];
    int top=-1;
    TreeNode *p=t;
    TreeNode *x;
    while(p||top!=-1)
    {
        if(p)
        {
            top++;
            stack[top]=p;
            p=p->lchild;
        }
        else
        {
            p=stack[top];
            if(p->rchild&&p->rchild->tag==0)
                p=p->rchild;
            else
            {
                p=stack[top];
                top--;
                cout<<p->data<<" ";
                p->tag=1;
                p=NULL;
            }
        }
    }
}
int main()
{
    Tree t;
    creattree(t);
    back(t);
    return 0;
}
//ABDEC
//ABD##E##C##