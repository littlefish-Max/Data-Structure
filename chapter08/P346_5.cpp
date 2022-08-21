//P346（5）试设计一个算法，判断-一个数据序列是否构成一个小根堆。
#include<iostream>
using namespace std;
//判断是不是小根堆
int is_min(int a[],int len)
{
    //最后的序号为偶数
    if(len%2==0)
    {
        //判断单枝结点
        if(a[len/2]>a[len]) return 0;
        //判断双支结点
        for(int i=len/2-1;i>=1;i--)
        {
            if(a[i]>a[2*i]||a[i]>a[2*i+1])
                return 0;
        }
    }
    else
    {
        //为奇数
        for(int i=len/2;i>=1;i--)
        {
            //判断双支结点
            if(a[i]>a[i*2]||a[i]>a[i*2+1])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int a[8]={1,1,3,2,5,4,0};
    cout<<is_min(a,6)<<endl;
    return 0;
}