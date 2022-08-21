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
//二叉排序树中最小关键字
char Min(tree t)
{
    while(t->lchild!=NULL)
    {
        t=t->lchild;
    }
    return t->data;
}
//二叉排序树中最大关键字
char Max(tree t)
{
    while(t->rchild!=NULL)
    {
        t=t->rchild;
    }
    return t->data;
}
int main()
{
  
    tree t;
    buildtree(t);
    cout<<Min(t)<<endl;
    cout<<Max(t)<<endl;
    return 0;
}
/*                 F 
            E              H
         C           G           I
    A       D
        B
FECA#B##D###HG##I##
*/