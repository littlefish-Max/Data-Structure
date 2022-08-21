//P217（5）假设图用邻接表表示，设计一个算法，输出从顶点Vi到顶点Vj的所有简单路径。

void FindPath(AGraph *G,int u,int v,int path[],int d)
{
    //添加当前结点到路径当中  首先路径要+1 再加入结点
    d++;
    path[d]=u;
    //这时候当前结点访问过
    visited[u]=1;
    //如果该点为路径终点 就输出
    if(u==v) cout<<path<<endl;
    //指向u的邻接点 即第一个相邻点
    ArcNode *p=G->adjlist[u].firstarc;
    //不断去访问相邻点的下一个邻接点 往深处去搜索
    while(p!=NULL)
    {
    //获取当前的邻接点的弧所指向顶点的位置
    int w=p->adjvex;
    //如果这个点没有访问过 递归地去往下找
    if(visited[w]==0)
        FindPath(G,w,v,path,d);
    //之后p后移
        p=p->nextarc;
    }
    //为了该点可以重新使用 visit=0
    visited[u]=0;
}