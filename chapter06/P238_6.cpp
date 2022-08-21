//P238（6）试说明利用DFS如何实现有向无环图拓扑排序。
int finishtime[Max];
//访问的标记数组
bool visited[Max];
void DFS(Graph G,int v)
{
    //访问当前结点
    visited[v]=true;
    visit(v);
    //深度遍历邻接结点
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
    {
        if(!visited[w]) DFS(G,W);
    }
    //时间存储
    time++;
    finishtime[v]=time;
}
void DFSTraverse(Graph G)
{
    //初始化标记数组
    for(int i=0;i<G.vexnum;i++)
    {
        visited[i]=false;
    }
    //初始化时间
    time=0;
    //DFS每个没有被访问过的结点
    for(int v=0;v<G.vexnum;i++)
    {
        if(!visited[v]) DFS(G,v);
    }
}