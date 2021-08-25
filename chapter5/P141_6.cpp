//中序先序构造二叉树
#include<bits/stdc++.h>
using namespace std;
typedef struct treenode{
    char data;
    struct treenode *lchild,*rchild;
}treenode,*tree;
int pos=0;
tree build(char a[],char b[],int s,int e)
{
    if(s<=e)
    {
        treenode *root=(treenode *)malloc(sizeof(treenode));
        root->data=a[pos];
        int i;
        for(i=s;i<=e;i++) if(b[i]==root->data) break;
        pos++;
        root->lchild=build(a,b,s,i-1);
        root->rchild=build(a,b,i+1,e);
        return root;
    }
    return NULL;
}
void disp(tree t)
{
    if(t)
    {
        disp(t->lchild);
        disp(t->rchild);
        cout<<t->data<<" ";
    }
}
int main() {
    char a[]={'A','B','D','E','C','F'};//先序序列
    char b[]={'D','B','E','A','F','C'};//中序序列
    tree root=build(a,b,0,5);
    cout<<"后序序列为:"<<endl;
    disp(root);
	return 0;
}
/*        A
       /    \
      B      C
     / \    /
    D   E  F
*/