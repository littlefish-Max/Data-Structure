//假设二叉树采用二叉链存储结构存储，设计-个算法，求先序遍历序列中第k(1≤k≤二叉树中结点个数)个结点的值.
#include<iostream>
using namespace std;
//结构体
typedef struct treenode{
//结点的值
    char data; 
//结点的左右孩子指针
    struct treenode *lchild,*rchild;
}treenode,*tree;
//建树 赋值结点
void buildtree(tree &t)
{
    char ch;
    ch=getchar();
    if(ch=='#') t=NULL;
    else
    {
        //对结点就行内存分配
        t=(treenode *)malloc(sizeof(treenode));
        //对结点进行赋值
        t->data=ch;
        //初始化 左右孩子结点为空
        t->lchild=NULL;
        t->rchild=NULL;
        //递归去赋值左右子树
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//先序遍历 递归

//计数器
int i=1;
//字符
char ch;
char PreNode(tree t,int k)
{
    if(t==NULL) return '#';
    if(i==k) return t->data;
    i++;
    ch=PreNode(t->lchild,k);
    if(ch!='#') return ch;
    ch=PreNode(t->rchild,k);
    return ch;
}
//主函数 测试
int main()
{
    tree t;
    buildtree(t);
    cout<<PreNode(t,7)<<endl;
    return 0;
}


/*

             A                            
          B    C                    
        D  E  F  G                 
      
ABD##E##CF##G##                  

*/