//127. Word Ladder
//tag:dp dynamic programming,
//问题描述：给定两个词beginword和endword，和字典，返回begin到end最短的变换序列长度，变换：次只能更改一个字母。每个转换字必须存在于单词列表中。
//思路：1.构造图，可变换的两个词间有边连接(邻接表的形式)
//      2.用BFS遍历图，寻找最短路径,层次遍历
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        vector<string>::iterator st = find(wordList.begin(),wordList.end(),beginWord);
        vector<string>::iterator end = find(wordList.begin(),wordList.end(),endWord);
        if(end==wordList.end())//特殊情况终点不在字典中返回空路径
            return ans;
        int endindex = end - wordList.begin();
        //1.构造邻接表形式的图
        int n = wordList.size(); //图中节点数
        vector<vector<int> > graph(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(diffbits(wordList[i],wordList[j])==1){//构建邻接表
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        //2.BFS遍历图 层次遍历
        vector<bool> visit(n,0);//标记图是否已经遍历经过
        queue<int> q;
        int pathlen;
        if(st==wordList.end()){//当起点不在字典中则
            for(int i=0;i<n;i++){
                if(diffbits(beginWord,wordList[i])==1)
                    q.push(i);
            }
            pathlen = 1;
        }else{
            int stindex = st - wordList.begin();
            q.push(stindex);//起点在字典中
            pathlen = 0;
        } 
        while(!q.empty()){
            pathlen++;
            vector<int> curlevel;
            while(!q.empty()){//取出当前层次所有的节点
                int curnode = q.front();
                visit[curnode] = 1;//标记访问
                q.pop();
                if(curnode==endindex)//到终点则退出
                    return pathlen;
                curlevel.push_back(curnode);
            }
            for(int i=0;i<curlevel.size();i++){
                int curnode = curlevel[i];
                for(int j=0;j<graph[curnode].size();j++){
                    if(!visit[graph[curnode][j]])//将未访问的当前结点的边压入队列
                        q.push(graph[curnode][j]);
                }
            }
        }
        return ans;
    }
    int diffbits(string a,string b){
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
                ans++;
        }
        return ans;
    }
};