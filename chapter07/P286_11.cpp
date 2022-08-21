//P286（11）编写-一个递归算法，在一棵有n个结点的、随机建立起来的二叉排序树上查找第k(1≤k≤n)小的元素，并返回指向该结点的指针。
//要求算法的平均时间复杂度为0(log2n).二叉排序树的每个结点中除data, lchild, rchild 等数据成员外，增加一-个count成员，保存以该结点为根的子树上的结点个数。


//存储结构
typedef struct treenode{
    //结点值    
    char data;
    //左右孩子指针
    struct treenode *lchild,*rchild;
    //子树包括根的所有结点个数
    int count;
}treenode,*tree;
//第k小元素
treenode *min_k(tree t,int k)
{
    //k合法条件
    if(k<1||k>t->count) return NULL;
    //左子树空的情况
    if(t->lchild==NULL) 
    {
        //k=1就是根结点
        if(k==1) return t;
        //k不为1 就是到右子树中找第k-1小 根结点已考虑
        else min_k(t->rchild,k-1);
    }
    //左子树不为空 
    else
    {
        //左子树结点个数为k-1 结果就是根结点
        if(t->lchild->count==k-1) return t;
        //左子树结点个数>k-1 在左子树中找第k小
        if(t->lchild->count>k-1) return min_k(t->lchild,k);
        //左子树结点个数<k-1 在右子树中找第k-(左子树结点个数)小的元素
        if(t->lchild->count<k-1) return min_k(t->rchild,k-(t->lchild->count+1));
    }
}

