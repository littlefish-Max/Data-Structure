//判断是否是完全二叉树
#include<bits/stdc++.h>
using namespace std;
#define Max 13
typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
void buildtree(tree t)
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
struct squeue1{
    struct treenode *data[Max];
    int f,r,tag;
};
bool isempty(squeue1 s)
{
    if(s.f==s.r&&s.tag==0) return true;
    return false;
}
bool isfull(squeue1 s)
{
    if(s.f==s.r&&s.tag==1) return true;
    return false;
}
bool enters(squeue1 s,treenode *p)
{
    if(isfull(s)) return false;
    s.data[s.r]=p;
    s.r=(s.r+1)%Max;
    s.tag=1;
    return true;
}
bool outs(squeue1 s,treenode *&p)
{
    if(isempty(s)) return false;
    p=s.data[s.f];
    s.f=(s.f+1)%Max;
    s.tag=0;
    return 0;
}
bool isok(tree t)
{
    squeue1 s;
    s.f=s.r=s.tag=0;
    if(!t) return true;
    enters(s,t);
    cout<<"1 "<<t->data<<endl;
    treenode *p;
    while(!isempty(s))
    {
        outs(s,p);
        cout<<"2 "<<p->data<<endl;
        if(p)
        {
            enters(s,p->lchild);
            enters(s,p->rchild);
        }
        else
        {
            while(!isempty(s))
            {
                outs(s,p);
                if(p) return false;
            }
        }
    }
    return true;
}
int main()
{
    tree t;
    buildtree(t);
    if(isok(t)) cout<<"是完全二叉树"<<endl;
    else cout<<"非完全二叉树"<<endl;
    return 0;
}
//ABD##E##CF##G##
//ABD###CE##F##