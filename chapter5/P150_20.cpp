//P150（20）表达式树转化成中缀表达式
#include<iostream>
using namespace std;
//结构体
typedef struct treenode{
    //结点值
    char data;
    //左右孩子的指针
    struct treenode *lchild,*rchild;
}treenode,*tree;
//建树
void buildtree(tree &t)
{
    char ch;
    cin>>ch;
    if(ch=='#') t=NULL;
    else
    {
        //分配内存空间
        t=(treenode *)malloc(sizeof(treenode));
        //赋值
        t->data=ch;
        //初始化
        t->lchild=NULL;
        t->rchild=NULL;
        //递归去赋值
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//转化函数
void toexp(tree t,int deep)
{
    if(t==NULL) return;
    else if(t->lchild==NULL&&t->rchild==NULL)
    {
        cout<<t->data;
    }
    else
    {
        if(deep>1) cout<<"(";
        toexp(t->lchild,deep+1);
        cout<<t->data;
        toexp(t->rchild,deep+1);
        if(deep>1) cout<<")";
    }
}
//主函数测试
int main()
{
    tree t;
    buildtree(t);
    toexp(t,1);
    return 0;
}

/*

        *
    +       *
  a   b   c  -
  *+a##b##*c##-#d##

            +
        *      -
    a    b         -
                c     d

  +*a##b##-#-c##d##


   +
 a   b
  +a##b##
*/