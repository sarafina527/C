// 很差的寫法，點從queue彈出來之後才設定遍歷過了。
bool adj[9][9];
bool visit[9];
 
void BFS()
{
    queue<int> q;
 
    for (int i=0; i<9; i++)
        visit[i] = false;
 
    for (int k=0; k<9; k++)
        if (!visit[k])
        {
            q.push(k);
 
            while (!q.empty())
            {
                int i = q.pop();
 
                if (!visit[i])
                {
                    visit[i] = true;
 
                    for (int j=0; j<9; j++)
                        if (adj[i][j] && !visit[j])
                            q.push(j);
                }
            }
        }
}