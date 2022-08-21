//P360（2）设顺序表用数组A[]表示，表中元素存储在数组下标1~m+ n的范围内，前m个元素递增有序，后n个元素递增有序，设计一个算法，使得整个顺序表有序。
#include<iostream>
using namespace std;
void insertsort(int a[],int m,int n)
{
    //两个遍历指针
    int i,j;
    //第一个遍历范围
    for(i=m+1;i<=m+n;i++)
    {
        //复制哨兵
        a[0]=a[i];
        for(j=i-1;a[j]>a[0];j--)
        {
            a[j+1]=a[j];
        //后移
        }
        a[j+1]=a[0];
        //插入哨兵值
    }
}
int main()
{
    int a[8]={0,1,3,5,7,2,4,9};
    insertsort(a,4,3);
    for(int i=1;i<=7;i++) cout<<a[i]<<" ";
    return 0;
}
