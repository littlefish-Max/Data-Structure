//P150(15)设有一棵满二叉树(所有结点值均不同)，已知其先序序列为pre,设计一个算法求其后序序列post.
#include<iostream>
using namespace std;
//递归交换过程
void PrePost(char pre[],int l1,int h1,char post[],int l2,int h2)
{
    int half;//左右子树临界
    if(l1<=h1)//递归条件
    {
        post[h2]=pre[l1];
        half=(h1-l1)/2;
        PrePost(pre,l1+1,l1+half,post,l2,l2+half-1);
        PrePost(pre,l1+half+1,h1,post,l2+half,h2-1);
    }
}
//主函数 测试
int main()
{
    char pre[8]="ABDECFG",post[8];
    PrePost(pre,0,6,post,0,6);
    for(int i=0;i<7;i++)
    {
        cout<<post[i]<<" ";
    }
    return 0;
}

/*

             A                            
          B    C                    
        D  E  F  G                 
              p  q
ABD##E##CF##G##                  

*/