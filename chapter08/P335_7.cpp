//P335(7) |n1-n2|最小 ｜s1-s2|最大
#include<bits/stdc++.h>
using namespace std;

//快排
void seta(int a[],int n,int low,int high)
{
    //非递归
    int flag=1;
    //取中间值 后面与基准值进行比较
    int k=(high-low)/2;
    //非递归条件
    while(flag)
    {
        //快排
         //i一开始指向low位置
        int i=low;
        //从第二个开始遍历到结束
        int p=a[low];
        for(int j=low+1;j<=high;j++)
        {
        //如果小于基准值
        if(a[j]<p) 
                swap(a[++i],a[j]);
            //交换到前面去
        }
        //将基准元素插入到最终的位置
        swap(a[low],a[i]);
       //返回基准元素的位置

        //如果基准值刚好等于s1的右端 结束
        if(i==k-1) flag=0;
        //如果基准值小于 则在右端进行快排 继续找到中间值的位置
        else if(i<k-1) low=i+1;
        //否则在左端
        else high=i-1;
    }
    //计算两个集合的和
   int s1=0,s2=0;
   cout<<"s1= ";
   for(int i=0;i<k;i++)
   {
       s1+=a[i];
       cout<<a[i]<<" ";
   }
    cout<<endl;
     cout<<"s2= ";
    for(int i=k;i<n;i++)
    {
        s2+=a[i];
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    cout<<abs(s1-s2)<<endl;
}
int main()
{
    int a[9]={0,-1,-2,0,-10,3,-4,1};
    seta(a,8,0,8);
    return 0;
}