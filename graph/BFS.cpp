//2.BFS遍历图
int BFS(vector<vector<int> > &graph,int spos,int epos,map<int,vector<int> >&pi){
    int n = graph.size();
    vector<bool> visit(n,0);//标记图是否已经遍历经过
    vector<int> dist(n,0);//标记结点离起点的距离
    queue<int> q;
    int pathlen = INT_MAX;
    q.push(spos);
    visit[spos] = 1;//标记访问
    while(!q.empty()){//层次遍历
        int cur = q.front();q.pop();
        if(cur==epos){//当前层次已经找到dest
            pathlen = dist[cur];
            break;
        }
        for(int j=0;j<graph[cur].size();j++){//所有邻接点
            int next = graph[cur][j];
            if(!visit[next]){//将未访问的当前结点的边压入队列
                q.push(next);
                visit[next] = 1;
                dist[next] = dist[cur]+1;
            }
        }
    }
    return pathlen;
}