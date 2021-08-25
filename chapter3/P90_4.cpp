//队列的应用
#include<iostream>
using namespace std;
#define Max 10
struct squeue{
    int data[Max];
    int f,r,tag;
};
bool isempty(squeue s)
{
    if(s.f==s.r&&s.tag==0) return true;
    return false;
}
bool isfull(squeue s)
{
    if(s.f==s.r&&s.tag==1) return true;
    return false;
}
bool entersqueue(squeue &s,int x)
{
    if(isfull(s)) return false;
    s.data[s.r]=x;
    s.r=(s.r+1)%Max;
    s.tag=1;
    return true;
}
bool outsqueue(squeue &s,int &x)
{
   if(isempty(s)) return false;
   x=s.data[s.f];
   s.f=(s.f+1)%Max;
   s.tag=0;
   return true;
}
void disp(squeue &s)
{
    while(!isempty(s))
    {
        cout<<s.data[s.f]<<" ";
        s.f=(s.f+1)%Max;
        s.tag=0;
    }
    cout<<endl;
}
void car()
{
    squeue ans,k,h;
    ans.f=ans.r=0;ans.tag=0;
    k.f=k.r=0;k.tag=0;
    h.f=h.r=0;h.tag=0;
    for(int i=0;i<Max;i++)
    {
        entersqueue(k,1);
        entersqueue(h,2);
    }
    int i=0,j=0,x;
    while(j<10)
    {
        if(!isempty(k)&&i<4)
        {
            outsqueue(k,x);
            entersqueue(ans,x);
            i++;j++;
        }
        else if(i==4&&!isempty(h))
        {
            outsqueue(h,x);
            entersqueue(ans,x);
            j++;i=0;
        }
        else
        {
            while(j<10&&i<4&&isempty(h))
            {
                outsqueue(h,x);
                entersqueue(ans,x);
                i++;j++;
            }
            i=0;
        }
        if(isempty(k)&&isempty(h)) j=11;
    }
    cout<<"客车队列"<<endl;// 1 1 1 1 1 1 1 1 1 1 
    disp(k);
    cout<<"货车队列"<<endl;// 2 2 2 2 2 2 2 2 2 2
    disp(h);
    cout<<"目标队列"<<endl;
    disp(ans);

}
int main()
{
    car();
    return 0;
}