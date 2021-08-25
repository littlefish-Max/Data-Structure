//交换左右子树
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
void swap(tree &t)
{
    treenode *p;
    if(t)
    {
        swap(t->lchild);
        swap(t->rchild);
        p=t->lchild;
        t->lchild=t->rchild;
        t->rchild=p;
    }
}
void disp(tree t)
{
    if(t)
    {
        cout<<t->data<<" ";
        disp(t->lchild);
        disp(t->rchild);
    }
}
int main()
{
    tree t;
    buildtree(t);
    cout<<"交换过后的二叉树为(前序序列):"<<endl;
    swap(t);
    disp(t);
    return 0;
}
/*

             A                            A
          B    C                       C     B
        D  E  F  G                   G   F   E  D  

ABD##E##CF##G##                   ACGFBED 

*/