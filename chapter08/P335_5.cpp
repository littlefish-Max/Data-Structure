#include<iostream>
using namespace std;
int min_k(int a[],int low,int high,int k)
{
    //快速排序划分算法
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
    if(i==k) return a[i];
    //若最后基准的位置为k的话  那么基准就是第k小
    else if(i>k) return min_k(a,low,i-1,k);
    //若最后基准的位置>k的话 则在基准左边递归去找
    else return min_k(a,i+1,high,k);
    //若最后基准的位置<k的话 则在基准右边递归去找
   
}
int main()
{
    int a[10]={0,7,5,9,2,6,4,3,8,1};
    cout<<min_k(a,1,9,8)<<endl;
    return 0;
}