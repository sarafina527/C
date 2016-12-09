bool adj[9][9]; // 一張圖，資料結構為adjacency matrix。
bool visit[9];  // 紀錄圖上的點是否遍歷過，有遍歷過為true。
 
void DFS(int i)
{
    for (int j=0; j<9; j++)
        if (adj[i][j] && !visit[j])//找到未访问的邻接点
        {
            visit[j] = true;    // 標記為已遍歷
            DFS(j);
        }
}
 
void traversal()
{
    // 全部的點都初始化為尚未遍歷
    for (int i=0; i<9; i++)
        visit[i] = false;
 
    for (int i=0; i<9; i++)
        if (!visit[i])
        {
            visit[i] = true;
            DFS(i);
        }
}