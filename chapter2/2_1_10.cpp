//循环左移
#include<bits/stdc++.h>
using namespace std;

int a[7]={1,2,3,4,5,6,7};
int n=7;
void reverse(int a[],int l,int r)
{
    for(int i=l;i<=(l+r)/2;i++)
    {
        int t=a[i];
        a[i]=a[(l+r)-i];
        a[(l+r)-i]=t;
    }
}
void prin(int a[])
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl; 
}
void change(int a[],int left)
{
    cout<<"全部逆置"<<endl;
    reverse(a,0,n-1);
    prin(a);
    cout<<"前n-left个逆置"<<endl;
    reverse(a,0,n-left-1);
    prin(a);
    cout<<"后left个逆置"<<endl;
    reverse(a,n-left,n-1);
    prin(a);
}
int main()
{
    cout<<"一开始数组"<<endl;
    prin(a);
    change(a,6);
    return 0;
}