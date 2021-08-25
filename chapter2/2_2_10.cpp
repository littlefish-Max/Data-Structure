//分链表
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={2,7,4,1,9};
int n=5;
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
linklist L2;
void cut(linklist &L1)
{
    L2=(linklist)malloc(sizeof(lnode));
    L2->next=NULL;
    lnode *r1=L1,*r2=L2,*p=L1->next;
    int i=0;
    L1->next=NULL;
    while(p)
    {
        i++;
        if(i%2==0)
        {
            r2->next=p;
            r2=p;
        }
        else
        {
            r1->next=p;
            r1=p;
        }
        p=p->next;
    }
    r1->next=NULL;
    r2->next=NULL;
}
int main()
{
    linklist L1;
    buildlist(L1);
    cout<<"之前"<<endl;
    disp(L1);
    cut(L1);
    cout<<"L1: "<<endl;
    disp(L1);
    cout<<"L2"<<endl;
    disp(L2);
    return 0;
}