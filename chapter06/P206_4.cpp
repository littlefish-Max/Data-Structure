//P206（4）写出从图的邻接表表示转换成邻接矩阵表示的算法。
#include<iostream>
using namespace std;

//邻接表存储结构
//边表的结点
typedef struct Arcnode{
    //当前弧指向顶点的位置
    int adjvex;
    //指向下一条弧的指针
    struct Arcnode *next;
}Arcnode;
//顶点表结点
typedef struct Vnode{
    //顶点信息
    char data;
    //指向第一条依附该顶点的弧的指针
    Arcnode *first;
}Vnode,AdjList[10];

//组合的邻接表
typedef struct{
    //邻接表
    AdjList v;
    //顶点数和弧数
    int vnum,arcnum;
}ALGraph; 

//转换函数
void Convert(ALGraph &G,int arcs[M][N])
{
    //用来取边
    Arcnode *p;
    //遍历每条顶点表结点为头的边链表
    for(int i=0;i<n;i++)
    {
        //取顶点i的第一条出边
        p=(G.v[i]).first;
        
        //遍历该顶点表结点为头的边链表
        while(p!=NULL)
        {
            //置1
            arcs[i][p->adjvex]=1;
            //指向下一个结点 即取下一条边
            p=p->next;
        }
    }   
    
}
int main()
{

    return 0;
}