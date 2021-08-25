//合并有序线性表
#include<bits/stdc++.h>
using namespace std;
#define Max 50
struct sqlist{
    int data[Max];
    int length;
};
bool verge(sqlist a,sqlist b,sqlist &c)
{
    if(c.length<a.length+b.length) return false;
    int i=0,j=0,k=0;
    while(i<a.length&&j<b.length)
    {
        if(a.data[i]<=b.data[j]) c.data[k++]=a.data[i++];
        else c.data[k++]=b.data[j++];
    }
    while(i<a.length)
    {
        c.data[k++]=a.data[i++];
    }
    while(j<b.length)
    {
        c.data[k++]=b.data[j++];
    }
    c.length=a.length+b.length;
    return true;
}
int main()
{
    sqlist a={{2,3,4,6,7},5};
    sqlist b={{3,4,4},3};
    sqlist c;
    c.length=8;
    for(int i=0;i<a.length;i++) cout<<a.data[i]<<" ";
    cout<<endl;
    for(int i=0;i<b.length;i++) cout<<b.data[i]<<" ";
    cout<<endl;
    if(!verge(a,b,c)) cout<<"合并错误"<<endl;
    else{
        for(int i=0;i<c.length;i++){
            cout<<c.data[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}