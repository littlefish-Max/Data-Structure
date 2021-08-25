//中位数
#include<bits/stdc++.h>
using namespace std;
int a[5]={11,13,15,17,19};
int b[5]={2,4,6,8,20};
int c[10];
int verge(int a[],int b[],int c[])
{
    int i=0,j=0,k=0;
    while(i<5&&j<5)
    {
        if(a[i]<=b[j])    c[k++]=a[i++];
        else  c[k++]=b[j++];
    }
    while(i<5) c[k++]=a[i++];
    while(j<5) c[k++]=b[j++];
    return c[(k-1)/2];
}
int main()
{
    int t=verge(a,b,c);
    for(int i=0;i<10;i++) cout<<c[i]<<" ";
    cout<<"中位数:"<<t<<endl;
    cout<<endl;

    return 0;
}