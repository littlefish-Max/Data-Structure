//双链表查找元素 再排序
#include<iostream>
using namespace std;
typedef struct lnode{
    int data,f;
    struct lnode *next,*prior;
}lnode,*linklist;
int a[5]={1,2,3,4,5};
int n=5;
void buildlist(linklist &L)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *r=L,*s;
    L->prior=NULL;
    L->next=L;
    for(int i=0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=a[i];
        s->f=0;
        s->next=r->next;
        r->next->prior=s;
        r->next=s;
        s->prior=r;
        r=s;
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
linklist Locate(linklist &L,int x)
{
    lnode *p=L->next,*q;
    while(p&&p->data!=x) p=p->next;
    if(!p) cout<<"没有x这个结点"<<endl;
    else
    {
        p->f++;
        if(p->next!=NULL) p->next->prior=p->prior;
        p->prior->next=p->next;
        q=p->prior;
        while(q!=L&&q->f<=p->f) q=q->prior;
        p->next=q->next;
        q->next->prior=p;
        p->prior=q;
        q->next=p;
    }
    return p;
}
int main()
{
    linklist L;
    buildlist(L);
    disp(L);
    Locate(L,5);
    Locate(L,5);
    Locate(L,4);
    Locate(L,4);
    disp(L);
    return 0;
}