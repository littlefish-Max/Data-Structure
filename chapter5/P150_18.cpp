//写出在中序线索二叉树里查找指定结点在后序的前驱结点的算法。
#include<iostream>
using namespace std;
//线索二叉树结点结构体
typedef struct treenode{
    //结点的值
    char data;
    //左右孩子指针
    struct treenode *lchild,*rchild;
    //ltag rtag
    int ltag,rtag;
}treenode,*tree;
//建树 赋值结点
void buildtree(tree &t)
{
    char ch;
    cin>>ch;
    if(ch=='#') t=NULL;
    else
    {
        //分配内存
        t=(treenode *)malloc(sizeof(treenode));
        //赋值给结点
        t->data=ch;
        //初始化
        t->lchild=NULL;
        t->rchild=NULL;
        t->ltag=t->rtag=0;
        //递归赋值
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
tree pre;
//遍历二叉树的保留的前驱结点
//中序线索化
void zx(tree &t)
{
    //递归的条件
    if(t)
    {
        //向左延伸 找叶子结点
        zx(t->lchild);
        if(t->lchild==NULL) //左孩子空
        {
            t->ltag=1;
            t->lchild=pre;
        }
        else t->ltag=0;
        if(pre!=NULL&&pre->rchild==NULL)//没有右孩子
        {
            pre->rtag=1;//前驱结点有后继结点
            pre->rchild=t;//后继结点指向当前
        }
        pre=t;//更新前驱结点
        zx(t->rchild);
    }
}
//找后继的前驱结点
tree Inpostpre(tree t,treenode *p)
{
    //结果指针
    treenode *q;
    //该结点有右孩子 结果就是右孩子
    if(p->rtag==0) q=p->rchild;
    //该结点没有右孩子的情况下 有左孩子 结果就是左孩子
    else if(p->ltag==0) q=p->lchild;
    // 该结点的前驱为空 即为中序第一个结点 无后序前驱
    else if(p->lchild==NULL) q=NULL;
    //其他
    else
    {    
        //不断沿着线索找祖先结点
       while(p->ltag==1&&p->lchild!=NULL) 
        p=p->lchild;
       if(p->ltag==0) q=p->lchild;
        //若找到祖先结点 且有左孩子 结果就是左孩子
        else q=NULL;
        //最后就是没有后序前驱
    }   
    return q;
}

//主函数 测试
int main()
{
    tree t;
    buildtree(t);
    zx(t);
    cout<<Inpostpre(t,t->rchild)->data<<endl;
    return 0;
}

/*

             A                            
          B    C                    
        D  E  F  G                 
                
ABD##E##CF##G##                  

*/