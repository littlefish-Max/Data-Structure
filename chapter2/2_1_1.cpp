/*
从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行
*/
#include<bits/stdc++.h>
using namespace std;
#define Max 50
struct SqList{
    int a[Max]={};
    int length=0;
};
bool listdelete(SqList &s,int &ele)
{
    if(s.length==0)
        return false;
    int minn=s.a[0];
    int flag=0;
    for(int i=1;i<s.length;i++)
    {
        if(s.a[i]<minn)
        {
            minn=s.a[i];flag=i;
        }
    }
    ele=s.a[flag];
    s.a[flag]=s.a[s.length-1];
    return true;
}
int main()
{
   SqList s;
   cout<<"原先数组为:"<<endl;
   for(int i=0;i<s.length;i++) cout<<s.a[i]<<" ";
   cout<<endl;
   int k=0;
   if(listdelete(s,k))
   {
       cout<<"最小元素k="<<k<<endl;
       cout<<"修改之后的线性表为:"<<endl;
       for(int i=0;i<s.length;i++)
       {
           cout<<s.a[i]<<" ";
       }
       cout<<endl;
   }
   else{
       cout<<"错误"<<endl;
   }
    return 0;
}
