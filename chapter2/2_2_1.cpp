//不带头结点的链表数据删除
#include<bits/stdc++.h>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode;
int a[4]={1,3,3,4};
int n=4;
void buildlist(lnode *L)
{
    lnode *s,*r=L;
    r->data=a[0];
    if(n==1) r->next=NULL;
    else{
        for(int i=1;i<n;i++)
        {
            s=(lnode *)malloc(sizeof(lnode));
            s->data=a[i];
            r->next=s;
            r=r->next;
        }
        r->next=NULL;
    }
}
void disp(lnode *L)
{
    lnode *s=L;
    while(s)
    {
        cout<<(s->data)<<" ";
        s=s->next;
    }
    cout<<endl;
}
void deletex(lnode *&L,int x)
{
    if(L==NULL) return;
    lnode *p;
    if(L->data==x)
    {
        p=L;
        L=L->next;
        free(p);
        deletex(L,x);
    }
    else deletex(L->next,x);
}
int main()
{
    lnode list;
    lnode *L=&list;
    buildlist(L);
    disp(L);
    deletex(L,3);
    disp(L);
    return 0;
}
