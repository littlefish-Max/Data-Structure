//折半查找
#include<bits/stdc++.h>
using namespace std;
int a[10]={1,2,3,4,5,7,8,9,10};
int n=9;
void findd(int a[],int x)
{
    int left,right,mid;
    left=0,right=n-1;
    while(left<=right)
    {
       mid=(left+right)/2;
       if(a[mid]==x) break;
       else if(a[mid]>x) right=mid-1;
       else left=mid+1;
    }
    if(a[mid]==x&&mid!=n-1)
    {
        int t=a[mid];
        a[mid]=a[mid+1];
        a[mid+1]=t;
    }
    if(right<left){
        int i;
        for(i=n-1;i>right;i--)
        {
            a[i+1]=a[i];
        }
        a[i+1]=x;
    }
}
int main()
{
    for(int i=0;i<9;i++) cout<<a[i]<<" ";
    cout<<endl;
    findd(a,6);
    int i;
    for(i=0;i<10;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}