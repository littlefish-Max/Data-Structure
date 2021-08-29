//每次删除最小值且输出
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={2,5,3,8,1};
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
void deletemin(linklist &L)
{
    while(L->next!=NULL)
    {
        lnode *r=L,*p=r->next;
        while(p->next!=NULL)
        {
            if(p->next->data<r->next->data)
                r=p;
            p=p->next;
        }
        cout<<(r->next->data)<<" ";
        lnode *q=r->next;
        r->next=q->next;
        free(q);
    }
    free(L);
}
int main()
{
    linklist L;
    buildlist(L);
    deletemin(L);
    return 0;
}
