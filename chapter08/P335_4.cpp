//P335(4)试重新编写考点精析中的快速排序的划分算法，使之每次选取的枢轴值都是随机地从当前子表中选择的。
#include<bits/stdc++.h>
using namespace std;
void Partition2(int a[],int low,int high)
{
    //获取随机下标
    int root=low+rand()%(high-low+1);
    //交换到第一个
    swap(a[low],a[root]);
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
    return i;
}