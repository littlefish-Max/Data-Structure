//栈的运用
#include<bits/stdc++.h>
using namespace std;
#define Max 10
struct stack1{
    char data[Max];
    int top;
};
bool isempty(stack1 s)
{
    if(s.top==-1)return true;
    return false;
}
bool isfull(stack1 s)
{
    if(s.top==Max-1) return true;
    return false;
}
bool enterstack(stack1 &s,char x)
{
    if(isfull(s))
    {
        cout<<"栈满"<<endl;
        return false;
    }
    s.data[++s.top]=x;
    return true;
}
void outstack(stack1 &s,char &x)
{
    if(isempty(s))
    {
        cout<<"栈空"<<endl;
    }
    else
    {
        x=s.data[s.top--];
    }
}
void Sort(char str[])
{
    stack1 s;
    s.top=-1;
    char ans[Max+1];
    int j=0;
    for(int i=0;i<Max;i++)
    {
        if(str[i]=='H') enterstack(s,str[i]);
        else ans[j++]=str[i];
    }
    char c;
    while(!isempty(s))
    {
        outstack(s,c);
        ans[j++]=c;
    }
    for(int i=0;i<Max;i++)
        cout<<ans[i];
        cout<<endl;
}
int main()
{
    char str[Max+1]="HSHSHHHSHS";
    cout<<str<<endl;
    Sort(str);
    return 0;
}