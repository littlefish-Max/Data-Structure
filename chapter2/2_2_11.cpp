//链表拆分 头插法
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int n=10;
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
linklist L2;
void cutlist(linklist &L1)
{
    L2=(linklist)malloc(sizeof(lnode));
    L2->next=NULL;
    lnode *p=L1->next,*q,*r=L1;
    while(p)
    {
        r->next=p;
        r=p;
        p=p->next;
        if(p!=NULL) q=p->next;
        p->next=L2->next;
        L2->next=p;
        p=q;
    }
    r->next=NULL;
}
int main()
{
    linklist L1;
    buildlist(L1);
    cout<<"一开始L1"<<endl;
    disp(L1);
    cutlist(L1);
    cout<<"之后L1"<<endl;
    disp(L1);
    cout<<"之后L2"<<endl;
    disp(L2);
    return 0;
}