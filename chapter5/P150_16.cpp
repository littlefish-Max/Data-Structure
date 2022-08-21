//P150（16）设计一个算法将二叉树的叶结点按从左到右的顺序连成-一个单链表，表头指针为head.二叉树按二叉链表方式存储，链接时用叶结点的右指针域来存放单链表指针。
#include<iostream>
using namespace std;
//树结点结构体
typedef struct treenode{
    //          结点值
    char data;
    // 左右孩子指针
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
        //先内存非配给结点
        t=(treenode *)malloc(sizeof(treenode));
        //赋值
        t->data=ch;
        //左右孩子置空
        t->lchild=NULL;
        t->rchild=NULL;
        //递归去赋值
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
//全局 头结点 前驱结点 类型仍然是树结点的一个结构体 通过rchild连接起来
tree head=(treenode *)malloc(sizeof(treenode)),pre=NULL;
//中序遍历 
tree Inorder(tree t)
{
    //递归条件 结点不为空
    if(t)
    {
        //将根结点左孩子作为参数 一直递归向左延伸  
        Inorder(t->lchild);
        //找到叶子结点 
        if(t->lchild==NULL&t->rchild==NULL)
        {
            //如果是第一个
            if(pre==NULL)
            {
                //头结点赋值
                head=t;
                //保留前驱结点 前驱结点为当前的一个结点 保证后面再次遇到叶子结点的时候知道前驱结点是谁 并能够连接起来
                pre=t;
            }
            //若不是第一个
            else
            {
                //就将前驱结点的右指针指向当前的结点
                pre->rchild=t;
                //更新前驱结点 保证后面再次遇到叶子结点的时候知道前驱结点是谁 并能够连接起来
                pre=t;
            }
        }
        //左子树递归完成了 向左递归右子树
        Inorder(t->rchild);
        //右子树递归完成后可以将最后一个结点也就是更新后的前驱结点的右指针指向空
        pre->rchild=NULL;
    }
     //最后返回头结点即可 可以通过头结点来遍历整个结点链
     return head;
}

//主函数 测试
int main()
{
   tree t;
   buildtree(t);
   Inorder(t);
   while(head)
   {
       cout<<head->data<<" ";
       head=head->rchild;
   }
   
    return 0;
}

/*

             A                            
          B    C                    
        D  E  F  G                 
                
ABD##E##CF##G##                  

*/