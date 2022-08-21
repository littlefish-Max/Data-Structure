//P335(6)荷兰国旗问题:设有一个仅由红、白、蓝三种颜色的条块组成的条块序列，请编写一个时间复杂度为O(n)的 算法，使得这些条块按红、白、蓝的顺序排好，即排成荷兰国旗图案。
#include<bits/stdc++.h>
using namespace std;

//按照负数0 正数来排数组
void num(int a[],int n)
{
    //三个指针的指向 初始化
  int i=0,j=0,k=n-1;
    //循环体 j<=k
  while(j<=k)
  {
       int v;
       if(a[j]>0) v=1;
       else if(a[j]==0) v=0;
       else v=-1;
       //switch判断a[j]的值 
        switch (v)
        {
             //负数 和i交换
             case -1:swap(a[i],a[j]);i++;j++;break;
             //0 遍历指针+1
             case 0:j++;break;
             //正数 和k交换
             case 1:swap(a[j],a[k]);k--;break;
        }
  } 
}
int main()
{
    int a[9]={0,-1,-2,0,0,3,-4,1};
    num(a,8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    return 0;
}