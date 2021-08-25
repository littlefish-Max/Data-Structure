//判断循环双链表是否是对称的
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next,*prior;
}lnode,*linklist;
int a[6]={1,2,3,4,2,1};
int n=6;
void buildlist(linklist &L)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=L;
    L->prior=L;
    L->next=L;
    for(int i=0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=a[i];
        s->next=r->next;
        r->next->prior=s;
        s->prior=r;
        r->next=s;
        r=s;
        L->prior=s;
    }
}
void disp(linklist L)
{
    lnode *s=L->next;
    while(s!=L)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
bool isok(linklist L)
{
    lnode *p=L->next,*q=L->prior;
    while(p!=q&&q->next!=p)
    {
        if(p->data==q->data)
        {
            p=p->next;
            q=q->prior;
        }
        else return false;
    }
    return true;
}
int main()
{
    linklist L;
    buildlist(L);
    disp(L);
    if(isok(L))cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}