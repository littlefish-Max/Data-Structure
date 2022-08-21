//P150(19)带权路径长度之和
#include<iostream>
using namespace std;
//结构体
typedef struct treenode{
    //结点的值
    char weight;
    //左右孩子指针
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
        //分配空间
        t=(treenode *)malloc(sizeof(treenode));
        //赋值
        t->weight=ch;
        //初始化
        t->lchild=NULL;
        t->rchild=NULL;
        //递归赋值
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//计算WPL
int wplpre(tree t,int deep)
{
    //静态变量 存储结果值并函数末尾返回
    static int ans=0;
    //若是叶子结点 累加值
    if(t->lchild==NULL&&t->rchild==NULL)
        ans+=(deep*((t->weight)-'0'));
    if(t->lchild!=NULL)
        wplpre(t->lchild,deep+1);
    //若不是叶子结点 递归遍历左子树找叶子结点同时层数+1
    if(t->rchild!=NULL)
        wplpre(t->rchild,deep+1);
    //若不是叶子结点 递归遍历左子树找叶子结点同时层数+1
    return ans;    
}
//主函数测试

int main()
{
    tree t;
    buildtree(t);
    cout<<wplpre(t,0)<<endl;
    return 0;
}

/*

             1                            
          2    3                    
        4  5  6  7                 
                
124##5##36##7##     
ans=(4+5+6+7)*2=44

*/