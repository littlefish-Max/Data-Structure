//循环单链表依次输出最小值并删除节点
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[5]={3,5,2,7,1};
int n=5;
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
    r->next=L;
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
void deletelist(linklist &L)
{
    lnode *p,*r,*min,*mp;
    while(L->next!=L)
    {
        p=L->next,r=L,min=p,mp=r;
        while(p!=L)
        {
            if(p->data<min->data)
            {
                min=p;
                mp=r;
            }
            else
            {
                r=p;
                p=p->next;
            }
        }
        cout<<min->data<<" ";
        mp->next=min->next;
        free(min);
    }
    free(L);
}
int main()
{
    linklist L;
    buildlist(L);
    cout<<"L:"<<endl;
    disp(L);
    deletelist(L);
    
    return 0;
}