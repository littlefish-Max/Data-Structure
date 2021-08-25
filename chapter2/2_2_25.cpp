//链表重组
#include<bits/stdc++.h>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[8]={1,2,3,4,5,6,7,8};
int n=8;
void buildlist(linklist &L)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=L;
    for(int i=0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=a[i];
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
void newlist(linklist &L)
{
    lnode *p,*q,*l,*r;
    p=L,q=L;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
        if(q->next!=NULL) q=q->next;
    }
    q=p->next;
    p->next=NULL;
    while(q)
    {
        r=q->next;
        q->next=p->next;
        p->next=q;
        q=r;
    }
    l=L->next;
    q=p->next;
    p->next=NULL;
    while(q)
    {
        r=q->next;
        q->next=l->next;
        l->next=q;
        l=q->next;
        q=r;
    }
}
int main()
{
    linklist L;
    buildlist(L);
    disp(L);
    newlist(L);
    disp(L);
    return 0;
}