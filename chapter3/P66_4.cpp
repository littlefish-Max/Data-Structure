//判断链表是否是中心对称的
#include<iostream>
using namespace std;
typedef struct lnode{
    char data;
    struct lnode *next;
}lnode,*linklist;
char s1[4]={'a','b','b','c'};
int n=4;
void buildlist(linklist &L)
{
    L=(linklist)malloc(sizeof(lnode));
    lnode *s,*r=L;
    for(int i=0;i<n;i++)
    {
        s=(lnode *)malloc(sizeof(lnode));
        s->data=s1[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
bool isok(linklist L,int n)
{
    char str[n/2];
    lnode *p=L->next;
    int i;
    for(i=0;i<n/2;i++)
    {
        str[i]=p->data;
        p=p->next;
    }
    i--;
    if(n%2!=0) p=p->next;
    while(p&&p->data==str[i])
    {
        i--;
        p=p->next;
    }
    if(i==-1) return true;
    return false;
}
int main()
{
    linklist L;
    buildlist(L);
    if(isok(L,n)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}