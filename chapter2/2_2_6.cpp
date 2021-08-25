//链表的直接插入排序
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[4]={8,7,6,5};
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
    cout<<endl;
}
void sortlist(linklist &L)
{
    lnode *p=L->next,*r=p->next,*f;
    p->next=NULL;
    p=r;
    while(p)
    {
        r=p->next;
        f=L;
        while(f->next!=NULL&&f->next->data<p->data) f=f->next;
        p->next=f->next;
        f->next=p;
        p=r;
    }
}
int main()
{
    linklist L;
    buildlist(L);
    disp(L);
    sortlist(L);
    disp(L);
    return 0;
}