//三元组最短距离
#include<bits/stdc++.h>
using namespace std;
#define Max 0x7fffffff
int abss(int a)
{
    if(a<0) return -a;
    else return a;
}
bool minn(int a,int b,int c)
{
    if(min(a,min(b,c))==a) return true;
    return false; 
}
int findd(int a[],int b[],int c[],int na,int nb,int nc)
{
    int i=0,j=0,k=0,ans=Max;
    while(i<na&&j<nb&&k<nc&&ans>=0)
    {
        int v=abs(a[i]-b[j])+abs(b[j]-c[k])+abs(c[k]-a[i]);
        if(v<ans) ans=v;
        if(minn(a[i],b[j],c[k])) i++;
        else if(minn(b[j],a[i],c[k])) j++;
        else k++;
    }
    return ans;
}
int main()
{
    int a[3]={-1,0,9},b[4]={-25,-10,10,11},c[5]={2,9,17,30,41};
    int na=3,nb=4,nc=5;
    cout<<findd(a,b,c,3,4,5)<<endl;
    return 0;
}