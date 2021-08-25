//括号匹配问题
#include<bits/stdc++.h>
using namespace std;
#define Max 10
struct stack1{
    char data[Max+1];
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
int outstack(stack1 &s,char &x)
{
    if(isempty(s))
    {
        cout<<"栈空"<<endl;
        return 0;
    }
    x=s.data[s.top--];
    return 1;
}
bool isright(char *str)
{
    stack1 s;
    s.top=-1;
    int i=0;
    char ans;
    while(str[i]!='\0')
    {
        if(str[i]=='('||str[i]=='['||str[i]=='{')   enterstack(s,str[i]);
        else if(str[i]==')')
        {
            outstack(s,ans);
            if(ans!='(') return false;
        }
        else if(str[i]==']')
        {
            outstack(s,ans);
            if(ans!='[') return false;
        }
        else if(str[i]=='}')
        {
             outstack(s,ans);
            if(ans!='{') return false;
        }
        i++;
    }
    if(isempty(s)) return true;
    return false;
}
int main()
{
    char *str=(char*)"()[](}{}()";
    cout<<str<<endl;
    if(!isright(str)) cout<<"括号不匹配"<<endl;
    else cout<<"括号匹配"<<endl;
    return 0;
}