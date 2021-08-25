//带头结点的链表删除最小元素（唯一）
#include<bits/stdc++.h>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[4]={23,12,5,34};
int n=4;
void buildlist(linklist &L)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *r=L,*s;
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
    cout<<endl;;
}
void deletemin(linklist &L)
{
    lnode *p=L->next,*q,*r=L,*s;
    q=p,s=r;
    while(p)
    {
        if(p->data<q->data)
        {
            q=p;
            s=r;
        }
        r=p;
        p=p->next;
    }
    s->next=q->next;
    free(q);
}
int main()
{
    linklist L;
    buildlist(L);
    disp(L);
    deletemin(L);
    disp(L);
    return 0;
}