//P175(5)以孩子兄弟链表为存储结构，请设计递归算法求树的深度。
#include<iostream>
using namespace std;
//结构体
typedef struct treenode{
    //结点值
    char data;
    //左孩子域 右兄弟域 指针
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
        //分配空间
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
//递归计算深度
int height(tree t)
{
    //空树 返回0
   if(t==NULL) return 0;
   else
   {
          //递归计算左孩子子树高度
        int l=height(t->child);      
          //递归计算右兄弟子树高度
        int r=height(t->rbro);
        return max(l+1,r);
   }
}
//主函数测试
int main()
{
    tree t;
    
    buildtree(t);
    cout<<height(t)<<endl;
    return 0;
}

/*

                 A
             B
         D       C
           E   F
ABD#E##CF####

*/