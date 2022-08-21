//P346（4）编写一个算法，在基于单链表表示的待排序关键字序列上进行简单选择排序。
#include<iostream>
using namespace std;
//链表存储结构
typedef struct lnode{
    int data;
    struct lnode *next;
}lnode,*linklist;
int a[10]={7,5,9,2,6,4,3,8,1};
int n=9;
//建立链表 不带头结点
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
//输出链表
void disp(linklist L)
{
    lnode *s=L;
    while(s)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
//简单选择排序
void selectsort(linklist &l)
{
    //五个指针 遍历表的指针的初始化
   lnode *h=l,*p,*s,*r,*q;
    //将表置空
    l=NULL;
    //最外面的循环条件
    while(h!=NULL)
    {
        //最大结点和工作指针的初始化
        s=p=h;
        //前驱结点的初始化
        q=r=NULL;
        //每一趟开始遍历
       while(p!=NULL)
      {
            //碰到更大的结点
            if(p->data>s->data)
            {
                //更新最大结点位置
               s=p;
                //更新最大结点的前驱
                r=q;
            }   
            q=p;
            p=p->next;
            //工作指针向后遍历时前驱指针和工作指针向后移
      }
        
        //若最大的是表头  将遍历表的指针后移
        
        if(s==h) h=h->next;
        else 
        {
            r->next=s->next;
        } 
        //插入结果链表当中
       s->next=l;
        //更新结果链表的头
        l=s;
        
    }
}
int main()
{
    lnode L;
    lnode *l=&L;
    buildlist(l);
    selectsort(l);
    disp(l);
    return 0;
}