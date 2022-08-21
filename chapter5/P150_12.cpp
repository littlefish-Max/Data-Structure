//设一棵二叉树的结点结构为(LLINK, INFO, RLINK)，ROOT为指向该二叉树根结点的指针，p和q分别为指向该二叉树中任意两个结点的指针，试编写算法ANCESTOR(ROOT,P,q,r)，找到P和q的最近公共祖先结点r。
#include<iostream>
using namespace std;
//树结点结构体
typedef struct treenode{
    //结点值
    char data;
    //左右孩子指针
    struct treenode *lchild,*rchild;
}treenode,*tree;
//结点栈的结构体
typedef struct{
    //树的结点
    treenode *t;
    //左右孩子访问变量 tag=0 左孩子访问过 =1右孩子访问过
    int tag;
}Stack;
//建树 赋值结点
void buildtree(tree &t)
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        //给结点分配空间
        t=(treenode *)malloc(sizeof(treenode));
        //对结点赋值
        t->data=ch;
        //左右孩子置空
        t->lchild=NULL;
        t->rchild=NULL;
        //递归赋值左右孩子
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//非递归后序遍历
tree Ancestor(tree t,treenode *p,treenode *q)
{
    //两个辅助栈
    Stack S1[10],S2[10];
    //栈顶指针的初始化
    int top1=0,top2;
    //遍历二叉树指针
    treenode *tt=t;
    //大循环体条件：当前遍历的结点不能为空或者栈1顶指针>0（栈不为空）
    while(tt!=NULL||top1>0)
    {
        //向左延伸压入栈
        while(tt!=NULL)
        {
            S1[++top1].t=tt;//压入栈中
            S1[top1].tag=0;//左孩子访问过
            tt=tt->lchild;//继续指向左孩子
        }
        while(top1!=0&&S1[top1].tag==1)//栈1不为空并且栈顶结点的tag=1 
        {
            //如果栈顶的结点就是p 就复制到栈2中 栈2的栈顶指针此时赋值 top1
            if(S1[top1].t==p)
            {
                for(int i=1;i<=top1;i++)
                {
                    S2[i]=S1[i];
                }
                top2=top1;
            }
            //如果栈顶的结点就是q 与栈一进行匹配  
            if(S1[top1].t==q)
            {
                for(int i=top1;i>0;i--)
                {
                    for(int j=top2;j>0;j--)
                    {
                        if(S2[j].t==S1[i].t)
                            return S1[i].t;
                    }
                }
            }
            top1--;   //退栈
        } 
        //栈不空时  将栈顶结点的tag=1 并且当前的一个结点指向该结点的右孩子
        if(top1!=0)
        {
            S1[top1].tag=1;
            tt=S1[top1].t->rchild;
        }
    }
    return NULL;
} 
//主函数 测试
int main()
{
    tree t;
    buildtree(t);
    treenode *p=t->rchild->lchild,*q=t->rchild->rchild;
    cout<<Ancestor(t,p,q)->data<<endl;
    return 0;
}

/*

             A                            
          B    C                    
        D  E  F  G                 
              p  q
ABD##E##CF##G##                  

*/