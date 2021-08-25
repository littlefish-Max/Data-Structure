//公共后缀起始结点
#include<bits/stdc++.h>
using namespace std;
typedef struct lnode{
    char data;
    struct lnode *next;
}lnode,*linklist;
char a[7]={'l','o','a','d','i','n','g'};
char b[5]={'b','e','i','n','g'};
int n1=7,n2=5;
void buildlist(linklist &L,char aa[],int n)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=L;
    for(int i=0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=aa[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void disp(linklist L)
{
    lnode *s=L->next;
    while(s)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
int length(linklist L)
{
    int ans=0;
    lnode *s=L->next;
    while(s)
    {
        ans++;
        s=s->next;
    }
    return ans;
}
linklist first(linklist L1,linklist L2)
{
    int len1=length(L1),len2=length(L2);
    int dist=abs(len1-len2);
    lnode *p=L1->next,*q=L2->next;
    if(len1>=len2)
    {
        while(dist--)
        {
            p=p->next;
        }
    }
    else
    {
        while(dist--)
        {
            q=q->next;
        }
    }
    while(p)
    {
        if(p->data!=q->data)
        {
            p=p->next;
            q=q->next;
        }
        else return p;
    }
    return p;
}
int main()
{
    linklist L1,L2;
    buildlist(L1,a,n1);
    buildlist(L2,b,n2);
    cout<<"L1:"<<endl;
    disp(L1);
    cout<<"L2:"<<endl;
    disp(L2);
    linklist ans=first(L1,L2);
    cout<<"公共后缀的起始结点为:"<<ans->data<<endl;
    return 0;
}