//P286（8）利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法。
#include<bits/stdc++.h>
using namespace std;
//树结点的存储结构
typedef struct treenode{
    //结点值
    char data;
    //左右孩子指针
    struct treenode *lchild,*rchild;
}treenode,*tree;
//建树
void buildtree(tree &t)
{
    char ch;
    cin>>ch;
    if(ch=='#') t=NULL;
    else{
        //分配空间
        t=(treenode *)malloc(sizeof(treenode));
        //赋值
        t->data=ch;
        //初始化
        t->lchild=NULL;
        t->rchild=NULL;
        //递归赋值
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//后序遍历 判断是否是平衡二叉树
void isAVL(tree t,int &ba,int &h)
{
    //左右子树的高度 平衡因子变量
    int h1,h2,b1,b2;
    //空树 高度为0 平衡因子为1
   if(t==NULL) 
   {
       h=0;
       ba=1;
   }
    //只有一个根结点 高度为1  平衡因子为1
   else if(t->lchild==NULL&&t->rchild==NULL)
   {
       h=1;
       ba=1;
   }
   else
   {
    //递归判断左子树
    isAVL(t->lchild,ba,h);
    //递归判断右子树
    isAVL(t->rchild,ba,h);
    //到根这里 更新树高
    h=max(h1,h2)+1;
    //判断左右子树高度绝对值之差
    if(abs(h1-h2)<=1)
    {
        ba=b1&&b2;
    }
    //判断左右子树平衡因子
    else ba=0;
   }
}
int main()
{
  
    tree t;
    buildtree(t);
    int ba,h;
    isAVL(t,ba,h);
    cout<<ba<<endl;
    return 0;
}
/*                 F 
            E              H
         C           G           I
    A       D
        B
FECA#B##D###HG##I##
*/