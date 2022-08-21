//假设二叉树采用二叉链表存储结构，设计一个算法，求非空二叉树b的宽度(即具有结点数最多的那一层的结点个数)。
#include<iostream>
using namespace std;
//树结点结构体
typedef struct treenode{
    // 结点值
    char data;
    // 左右孩子的指针
    struct treenode *lchild,*rchild;
}treenode,*tree;
//结点队列的结构体
typedef struct{
    tree data[10];
    int level[10];
    int f,r;
}Qu;
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
        //赋值
        t->data=ch;
        //左右孩子先置空
        t->lchild=NULL;
        t->rchild=NULL;
        //递归去赋值左右孩子
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//层次遍历
int width(tree b)
{
    //队列
    Qu Q;
    //出队结点的指向
    tree p;
    //保存出队的结点层次
    int k;
    //头尾指针初始化
    Q.f=Q.r=-1;
    //尾指针后移用来根结点入队
    Q.r++;
    //根结点入队
    Q.data[Q.r]=b;
    //根结点层次为1
    Q.level[Q.r]=1;
    //循环体  头指针小于尾指针可执行
    while(Q.f<Q.r)
    {
        //头指针后移出队
        Q.f++;
        //保存出队结点
        p=Q.data[Q.f];
        //保存出队结点的层次
        k=Q.level[Q.f];
        //左孩子进入队列
        if(p->lchild!=NULL)
        {
            //尾指针后移 用来入队
            Q.r++;
            //左孩子进入队列
            Q.data[Q.r]=p->lchild;
            //进入队列的结点的层次为出队结点的层次+1
            Q.level[Q.r]=k+1;
        }
        if(p->rchild!=NULL) //右孩子进队
        {
            //尾指针后移 用来入队
            Q.r++;
            //右孩子进入队列
            Q.data[Q.r]=p->rchild;
            //进入队列的结点的层次为出队结点的层次+1
            Q.level[Q.r]=k+1;
        }
    }
    //遍历的时候最大值的更新，遍历下标，计算每层的个数
    int maxx=0,i=0,n;
    //从第一层开始
    k=1;
    //循环条件 遍历的下标小于队列尾部
    while(i<=Q.r)
    {
        //一开始每层默认0个
        n=0;
        //当下标小于队列长度并且遍历的下标对应的层次为k的时候
        while(i<=Q.r&&Q.level[i]==k)
        {    //每层个数递增
            n++;
            //遍历的下标后移
            i++;
        }
        //下一层的层次
        k=Q.level[i];
        //更新最大值 
        if(n>maxx) maxx=n;
    }
    return maxx;
}
//主函数 测试
int main()
{
    tree t;
    buildtree(t);
    cout<<width(t)<<endl;
    return 0;
}

/*

             A                            
          B    C                    
        D  E  F  G                 
              p  q
ABD##E##CF##G##                  

*/