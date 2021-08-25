//用栈来模拟进栈出栈的操作
#include<iostream>
using namespace std;
#define Max 10
struct stack1
{
    int data[Max];
    int top;
};
bool isempty(stack1 s)
{
    if(s.top==-1) return true;
    return false;
}
bool isfull(stack1 s)
{
    if(s.top==Max-1) return true;
    return false;
}
bool enterstack(stack1 &s,int x)
{
    if(isfull(s)) return false;
    s.data[++s.top]=x;
    return true;
}
int outstack(stack1 &s,int &x)
{
    if(isempty(s)){
        cout<<"栈空"<<endl;
        return 0;
    }
    x=s.data[s.top--];
    return 1;
}
void disp(stack1 s)
{
    int top1=s.top;
    while(top1!=-1)
    {
        cout<<s.data[top1]<<" ";
        top1--;
    }
    cout<<endl;
}
int entersqueue(stack1 &s1,stack1 &s2,int x)
{
    if(!isfull(s1))
    {
        enterstack(s1,x);
        return 1;
    }
    else if(isfull(s1)&&!isempty(s2))
    {
        cout<<"队满"<<endl;
        return 0;
    }
    if(isfull(s1)&&isempty(s2))
    {
        while(!isempty(s1))
        {
            outstack(s1,x);
            enterstack(s2,x);
        }
    }
    enterstack(s1,x);
    return 1;
}
void outsqueue(stack1 &s1,stack1 &s2,int &x)
{
    if(!isempty(s2))
    {
        outstack(s2,x);
    }
    else if(isempty(s1))
    {
        cout<<"队空"<<endl;
    }
    else
    {
        while(!isempty(s1))
        {
            outstack(s1,x);
            enterstack(s2,x);
        }
        outstack(s2,x);
    }
}
bool squeueisempty(stack1 s1,stack1 s2)
{
    if(isempty(s1)&&isempty(s2)) return true;
    return false;
}
int main()
{
    stack1 s1,s2;
    s1.top=-1,s2.top=-1;
    for(int i=0;i<Max;i++)
    {
        enterstack(s1,i);
    }
    cout<<"s1:"<<endl;
    disp(s1);
    int x=0;
    outsqueue(s1,s2,x);
    cout<<"出队元素为: "<<x<<endl;
    disp(s2);
    return 0;
}