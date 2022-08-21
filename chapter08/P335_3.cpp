//P335(3)已知线性表按顺序存储，且每个元素都是不相同的整数型元素，设计把所有奇数移动到所有偶数前边的算法( 要求时间最少，辅助空间最少)。
#include<bits/stdc++.h>
using namespace std;
void Move(int a[],int n)
{
    //查找范围的左右两端
   int i=0,j=n-1;
    //循环遍历条件
    while(i<j)
    {
        //从前向后找偶数位置
        while(i<j&&a[i]%2==1) i++; 

        //从后向前找奇数位置
   
        while(i<j&&a[j]%2==0) j--;
        //若偶数在奇数前面 交换
        if(i<j)
        {
             //同时更新范围的左右端
             swap(a[i],a[j]);
             i++;
             j--;
        }
    }
}
int main()
{
    int a[10]={7,5,9,2,6,4,3,8,1};
    Move(a,9);
    for(int i=0;i<9;i++) cout<<a[i]<<" ";
    return 0;
}