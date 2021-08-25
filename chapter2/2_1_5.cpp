#include<bits/stdc++.h>
using namespace std;
#define Max 50
struct sqlist{
    int a[Max]={4,1,2,5,0,0,3};
    int length=7;
};
bool deletesqlist(sqlist &L,int s,int v)
{
    if(L.length==0||s>=v) return false;
    int k=0;
    bool flag=false;
    for(int i=0;i<L.length;i++)
    {
        if(L.a[i]>=s) {
            flag=true;break;
        }
    }
    if(!flag) return false;
    for(int i=0;i<L.length;i++)
    {
        if(L.a[i]>=s&&L.a[i]<=v) k++;
        else L.a[i-k]=L.a[i];
    }
    L.length=L.length-k;
    return true;
}
int main()
{
    sqlist L;
    for(int i=0;i<L.length;i++) cout<<L.a[i]<<" ";
    cout<<endl;
    if(!deletesqlist(L,3,5)) cout<<"错误"<<endl;
    for(int i=0;i<L.length;i++) cout<<L.a[i]<<" ";

    return 0;
}