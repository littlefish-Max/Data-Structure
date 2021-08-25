//不带头结点的逆序输出
#include<iostream>
using namespace std;
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode;
int a[4]={1,2,3,4};
int n=4;
void buildlist(lnode *L)
{
    lnode *r=L,*s;
    r->data=a[0];
    if(n==1) r->next=NULL;
    else
    {
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
    if(L!=NULL)
    {
        disp(L->next);
        cout<<(L->data)<<" ";
    }
    else return;
}
int main()
{
    lnode list;
    lnode *L=&list;
    buildlist(L);
    disp(L);
    return 0;
}