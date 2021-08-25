//删除带头结点的链表中的节点
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[4]={1,3,3,4};
int n=4;
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
void deletex(linklist &L,int x)
{
    lnode *p=L->next,*q,*r=L;
    while(p)
    {
        if(p->data!=x)
        {
            r->next=p;
            r=p;
            p=p->next;
        }
        else
        {
            q=p;
            p=p->next;
            free(q);
        }
    }
}
int main()
{
    linklist L;
    buildlist(L);
    disp(L);
    deletex(L,3);
    disp(L);
    return 0;
}