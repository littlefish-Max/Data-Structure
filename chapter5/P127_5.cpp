//二叉树找两个节点的公共祖先
#include<iostream>
using namespace std;
struct Tree
{
    /* data */
    int data[12]={-1,1,2,3,-1,4,-1,5,-1,-1,-6,-1};
};
int Comm(Tree t,int i,int j)
{
    if(t.data[i]!=-1&&t.data[j]!=-1)
    {
        while(i!=j)
        {
            if(i>j) i/=2;
            else j/=2;
        }
        return t.data[i];
    }
    return -1;
}
int main()
{
    Tree t;
    int ans=Comm(t,7,10);
    cout<<ans<<endl;
    return 0;
}