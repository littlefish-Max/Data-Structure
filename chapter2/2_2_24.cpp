//判断是否有环 链表
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode;
int a[15]={1,2,3,4,5,6,7,8,9,4,5,6,7,8,9};
int n=15;
void buildlist(lnode *L)
{
    lnode *s,*r=L;
    r->data=a[0];
    for(int i=1;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void disp(lnode *L)
{
    lnode *s=L;
    while(s)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
lnode* findd(lnode *L)
{
    lnode *f=L,*s=L;
    while(s!=NULL&&f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
        if(s->data==f->data) break;
    }
    if(s==NULL||f->next==NULL) return NULL;
    lnode *p=L,*q=s;
    while(p->data!=q->data)
    {
        p=p->next;
        q=q->next;
    }
    return p;
}
int main()
{
    lnode list;
    lnode *L=&list;
    buildlist(L);
    cout<<"L:"<<endl;
    disp(L);
    lnode *ans=findd(L);
    cout<<"环口值为:"<<ans->data<<endl;
    return 0;
}