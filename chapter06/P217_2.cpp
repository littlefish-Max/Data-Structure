//P217（2）试设计一个算法，判断一个无向图G是否为一-棵树。若是一-棵树，则算法返回true,否则返回false.

//DFS
void DFS(Graph &G,int v,int &Vnum,int &Enum,int visited[])
{
        visited[v]=true;//访问过
        Vnum++;//顶点数+1
        int w=FirstNeighbor(G,v);
        while(w!=-1)
        {
            //第一个邻接结点存在  存在边
            Enum++;//边+1
            if(!visited[w])//该邻接点有没有访问过
                DFS(G,W,Vnum,Enum,visited);//继续遍历
            w=NextNeighbor(G,v,w);//找下一个邻接点
        }
}

//判断是否是树
bool istree()
{
    //顶点数 边数
    int Vnum=0,Enum=0;
    //访问标记数组
    bool visited[Max];
    for(int i=0;i<Max;i++)
        visited[i]=false;
    DFS(G,1,Vnum,Enum,visited);
    if(Vnum==G.vexnum&&Enum==2*(G.vexnum-1))
        return true;
    return false;
}
