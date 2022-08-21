//P150（17）试设计判断两科二叉树是否相似的算法。所谓二叉树T1和T2相似，指的是T1和T2都是空的二叉树或都只有一个根结点；或T1的左子树和T2的左子树是相似的，且T1的右子树和T2的右子树是相似的
#include<iostream>
using namespace std;
//树结点结构体
typedef struct treenode{
        //结点的值
        char data;
        //左右孩子指针
        struct treenode *lchild,*rchild;
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
        //赋值
        t->data=ch;
        //左右孩子置空
        t->lchild=NULL;
        t->rchild=NULL;
        //递归的去赋值左右子树
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//递归比较左右子树  空+空 1 空+非空 0
int similar(tree t1,tree t2)
{
    int left,right;
    if(t1==NULL&&t2==NULL) return 1;
    else if(t1==NULL||t2==NULL) return 0;
    else
    {
        left=similar(t1->lchild,t2->lchild);
        right=similar(t1->rchild,t2->rchild);
        return (left&&right);
    }
}
//主函数 测试
int main()
{
    tree t1,t2;
    buildtree(t1);
    buildtree(t2);
    cout<<similar(t1,t2)<<endl;
    return 0;
}

/*

             A                            
          B    
    AB###
          C
              E
    C#E## 
*/