#include<bits/stdc++.h>
using namespace std;
//双向冒泡
void bsort(int a[],int n)
{
    //范围的左右两端
    int low=0,high=n-1;
    //一趟是否交换过 初始化
    bool flag=true;
    //循环条件 左端<右端并且一趟有交换
    while(low<high&&flag)
    {
        //排序前 默认一趟没有交换
        flag=false;
        //从前向后交换
        for(int i=low;i<high;i++)
        {
            if(a[i]>a[i+1])
            {
                swap(a[i],a[i+1]);
                flag=true;
            }
        }
        high--;
         //从后向前交换
        for(int i=high;i>low;i--)
        {
            if(a[i]<a[i-1])
            {
                swap(a[i],a[i-1]);
                flag=true;
            }
        }
       low++;
    }
}
int main()
{
    int a[10]={7,5,9,2,6,4,3,8,1};
    bsort(a,9);
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}