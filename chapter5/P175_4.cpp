//P175(4)编程求以孩子兄弟表示法存储的森林的叶子结点数。
#include<iostream>
using namespace std;
//结构体
typedef struct treenode{
    //结点值
    char data;
    //左孩子域 右兄弟域 指向
    struct treenode *child,*rbro;
}treenode,*tree;
//建树
void buildtree(tree &t)
{
    char ch;
    cin>>ch;
    if(ch=='#') t=NULL;
    else
    {
        //分配内存
        t=(treenode *)malloc(sizeof(treenode));
        //赋值
        t->data=ch;
        //初始化
        t->child=NULL;
        t->rbro=NULL;
        //递归赋值
        buildtree(t->child);
        buildtree(t->rbro);
    }
}
//递归找叶子结点
int leaves(tree t)
{
    //空结点 返回0
   if(t==NULL) return 0;
    //孩子为空即左孩子域为空  为叶子结点 结果加1还要加上右兄弟子树的叶子结点
   if(t->child==NULL) return 1+leaves(t->rbro);
    //有孩子 结果为左孩子子树和右兄弟子树的叶子结点个数之和
   else return leaves(t->child)+leaves(t->rbro);
}
//主函数测试
int main()
{
   tree t;
   buildtree(t);
   cout<<leaves(t)<<endl;
    return 0;
}

/*

         A
     B        F
  D     C   G
   \
    E
ABD#E##C##FG###

*/