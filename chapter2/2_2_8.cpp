//找公共结点
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={2,4,3,7,8};
int b[4]={1,3,7,8};
int n1=5,n2=4;
void buildlist(linklist &L,int aa[],int n)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=L;
    for(int i=0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=aa[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
int length(linklist L)
{
    int k=0;
    lnode *s=L->next;
    while(s)
    {
        k++;
        s=s->next;
    }
    return k;
}
linklist findd(linklist L1,linklist L2)
{
    int len1=length(L1),len2=length(L2);
    int dist=0;
    linklist long1,short1;
    if(len1>len2)
    {
        long1=L1->next;
        short1=L2->next;
        dist=len1-len2;
    }
    else
    {
        long1=L2->next;
        short1=L1->next;
        dist=len2-len1;
    }
    while(dist--) long1=long1->next;
    while(long1)
    {
        if(long1->data==short1->data&&long1->next->data==short1->next->data) return long1;
        else
        {
            long1=long1->next;
            short1=short1->next;   
        }
    }
    return NULL;
}
linklist findd2(linklist L1,linklist L2)
{
    lnode *s1=L1->next;
    while(s1)
    {
        lnode *s2=L2->next;
        while(s2)
        {
            if(s1->data==s2->data&&s1->next->data==s2->next->data)
            return s1;
            else s2=s2->next;
        }
        s1=s1->next;
    }
    return NULL;
}
int main()
{
    linklist L1,L2;
    buildlist(L1,a,n1);
    buildlist(L2,b,n2);
    linklist L3=findd2(L1,L2);
    cout<<L3->data<<" "<<endl;
    return 0;
}