//判断序列是否合法
#include<iostream>
using namespace std;
int n;
bool isok(char s[])
{
    int I=0,O=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='I') I++;
        else O++;
        if(O>I) return false;
    }
    if(O==I) return true;
    return false;
}
int main()
{
    char s[8]={'I','O','I','I','O','I','O','O'};
    n=8;
    if(isok(s)) cout<<"合法"<<endl;
    else cout<<"不合法"<<endl;
    return 0;
}