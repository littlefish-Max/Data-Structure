//P217（4）分别采用基于深度优先遍历和广度优先遍历算法判别以邻接表方式存储的有向图中是否存在由顶点v;到顶点y的路径(i#j).注意，算法中涉及的图的基本操作必须在此存储结构上实现。

//visited数组
int visited[Max];
//DFS
void DFS(ALGraph G,int i,int j,bool &isok)
{
    //如果当前结点就是j结点
    if(i==j)
    {
        //isok赋值 并退出函数
        isok=true;
        return;
    } 
    //否则更新访问标记
    visited[i]=1;
    //遍历邻接点 向后延伸
    for(int p=FirstNeighbor(G,i);p>=0;p=NextNeighbor(G,i,p))
    {    //没有找到j点并且该点没有访问过 继续DFS遍历
            if(!visited[p]&&!isok) DFS(G,p,j,isok);
    }
}

//BFS
int BFS(ALGraph G,int i,int j)
{
    //初始化队
    InitQueue(Q);
    //顶点入队
    EnQueue(Q,i);
    //循环体 遍历队
    while(!isempty(Q))
    {
     //出队 保留出队元素
     Dequeue(Q,u);
     //更新访问标记
     visited[u]=1;
     //如果当前点为j 即返回
     if(u==j) return 1;
     //否则遍历邻接点
     for(int p=FirstNeighbor(G,i);p>=0;p=NextNeighbor(G,i,p))
     {
        //再次判断是否为j点
        if(p==j) return 1;
        //是的话返回
        //不是 将邻接点入队
        if(!visited[p])
        {
            Enqueue(Q,p);
            visited[p]=1;
        //更新访问标记
        }

     }
    }
    return 0;
}