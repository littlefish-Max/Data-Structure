//判断是否是连续子序列
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[6]={1,2,3,4,5,6};
int b[3]={3,4,7};
int n1=6,n2=3;
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
bool isok(linklist L1,linklist L2)
{
    lnode *p1=L1->next,*p2=L2->next,*r=L1->next;
    while(p1&&p2)
    {
        if(p1->data!=p2->data)
        {
            r=r->next;
            p1=r;
            p2=L2->next;
        }
        else
        {
            p1=p1->next;
            p2=p2->next;
        }
    }
    if(p2) return false;
    else return true;
}
int main()
{
    linklist L1,L2;
    buildlist(L1,a,n1);
    buildlist(L2,b,n2);
    if(isok(L1,L2)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}