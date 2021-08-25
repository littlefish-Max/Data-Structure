#include<bits/stdc++.h>
using namespace std;
#define Max 50
struct sqlist{
    int a[Max]={2,2,3,3,3,5,6,6,7};
    int length=9;
};
void deletelist(sqlist &L)
{
    int black=1;
    for(int red=1;red<L.length;red++)
    {
        if(L.a[red]!=L.a[red-1])
        {
            L.a[black]=L.a[red];
            black++;
        }
    }
    L.length=black;
}
int main()
{
    sqlist L;
    for(int i=0;i<L.length;i++) cout<<L.a[i]<<" ";
    cout<<endl;
    deletelist(L);
    for(int i=0;i<L.length;i++) cout<<L.a[i]<<" ";
    return 0;
}