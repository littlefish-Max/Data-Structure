//非递归计算二叉树的高度
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
int dept(tree t)
{
    if(!t) return 0;
    tree q[10];
    int f=-1,r=-1;
    int L=0,ans=0;
    q[++r]=t;
    tree p;
    while(f<r)
    {
        p=q[++f];
        if(p->lchild) q[++r]=p->lchild;
        if(p->rchild) q[++r]=p->rchild;
        if(f==L)
        {
            ans++;
            L=r;
        }
    }
    return ans;
}
int main()
{
    tree t;
    buildtree(t);
    cout<<"树的高度为:"<<dept(t)<<endl;
    return 0;
}