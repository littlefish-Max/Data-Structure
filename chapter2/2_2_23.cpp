//保留链表绝对值相同的首个结点
#include<bits/stdc++.h>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[6]={1,-4,2,3,4,-2};
int n=6;
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
void same(linklist &L,int n)
{
    lnode *p=L;
    int *q;
    q=(int *)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n+1;i++) *(q+i)=0;
    int s;
    lnode *f;
    while(p->next!=NULL)
    {
        s=abs(p->next->data);
        if(*(q+s)==0) 
        {
            *(q+s)=1;
            p=p->next;
        }
        else
        {
            f=p->next;
            p->next=f->next;
            free(f);
        }
    }
    free(q);
}
int main()
{
    linklist L;
    buildlist(L);
    cout<<"L"<<endl;
    disp(L);
    same(L,4);
    cout<<"之后"<<endl;
    disp(L);
    return 0;
}