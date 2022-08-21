//P217（3）写出图的深度优先搜索DFS算法的非递归算法( 图采用邻接表形式)。

//非递归深度优先搜索
void DFS(AGraph &G,int v)
{
    //初始化栈
    stack S;
    InitStack(S);
    //初始化visited数组
    bool visited[G.vexnum+1];
    for(int i=0;i<G.vexnum;i++) visited[i]=false;
    //顶点压入栈中
    Push(S,v);
    visited[v]=true;
    //顶点已经被压入过 更新visited数组
    //退栈
    while(!Isempty(S))
    {
         k = Pop(S);
    //访问该结点 访问的顺序就是DFS顺序
         visit(k);
    //访问所有的邻接结点
    for(w=FirstNeighbor(G,k);w>=0;w=NextNeighbor(G,k,w))
    {
    //没有进过栈的话进栈
        if(!visited[w])
        {
            Push(S,w);
            visited[w]=true;
        }
    }
    }
}