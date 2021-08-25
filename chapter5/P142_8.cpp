//计算二叉树中双分支结点的个数
#include<bits/stdc++.h>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
void buildtree(tree &t)
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        t=(treenode *)malloc(sizeof(treenode));
        t->data=ch;
        t->lchild=NULL;
        t->rchild=NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
int num(tree t)
{
    if(!t) return 0;
    else if(t->lchild&&t->rchild) return num(t->lchild)+num(t->rchild)+1;
    else return num(t->lchild)+num(t->rchild);
}
int main()
{
    tree t;
    buildtree(t);
    cout<<"该二叉树中双分结点有 "<<num(t)<<" 个"<<endl;
    return 0;
}
/*
       A
     /  \
    B    C
  /\     /  \
 D E    F   G
 */
//前序序列:ABD##E##CF##G##
