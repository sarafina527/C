//126. Word Ladder II
//tag: BFS ,dp ,Backtacking,Array,String
//问题描述：给定两个词beginword和endword，和字典，返回begin到end最短长度的变换序列s，变换：次只能更改一个字母。每个转换字必须存在于单词列表中。初始节点不在字典中
//思路：1.构造图，可变换的两个词间有边连接(邻接表的形式)
//      2.用BFS遍历图，寻找最短路径
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        //0.找到起点和终点的下标
        int spos;
        vector<string>::iterator it = find(wordList.begin(),wordList.end(),beginWord);
        if(it==wordList.end()) wordList.push_back(beginWord);
        sort(wordList.begin(),wordList.end());
        it = find(wordList.begin(),wordList.end(),beginWord);
        spos = it - wordList.begin();
        it = find(wordList.begin(),wordList.end(),endWord);
        if(it==wordList.end()) return ans;//特殊情况终点不在字典中返回空路径   
        int epos = it - wordList.begin();//下标
        //1.构造邻接表形式的图
        int n = wordList.size();//节点数
        vector<vector<int> > graph(n,vector<int>());//最后一个节点存放开始节点
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(diffbits(wordList[i],wordList[j])==1){//构建邻接表
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        //2.BFS遍历图 层次遍历 反向遍历从尾部向
        vector<bool> visit(n,0);//标记图是否已经遍历经过
        vector<bool> enque(n,0);//标记图是否已经遍历经过
        map<int,vector<vector<int>> > path;
        queue<int> q;
        int pathlen = 0;
        q.push(spos);
        path[spos] = vector<vector<int> >(1,vector<int>(1,spos));
        while(!q.empty()){//层次遍历
            pathlen++;
            vector<int> curl;
            while(!q.empty()){//取出当前层次所有的节点
                int cur = q.front();q.pop();
                visit[cur] = 1;//标记访问
                if(cur==epos){//当前层次已经找到dest
                     generatePath(ans,path[cur],wordList,pathlen);
                     break;
                 }else{
                     curl.push_back(cur);
                }
            }
            for(int i=0;i<curl.size();i++){//入队下一层次
                int cur = curl[i];
                for(int j=0;j<graph[cur].size();j++){
                    int next = graph[cur][j];
                    if(!visit[next]&&!enque[next]){//将未访问的当前结点的边压入队列
                        q.push(next);
                        for(int i=0;i<path[cur].size();i++){
                            vector<int> tmp(path[cur][i].begin(),path[cur][i].end());
                            tmp.push_back(next);
                            path[next].push_back(tmp);
                        }
                    }
                }
            }
            for(int i=0;i<curl.size();i++){
                enque[curl[i]] = 1;
            }
        }
        return ans;
    }
    void generatePath(vector<vector<string> > &ans,vector<vector<int> >&paths,vector<string>& wordList,int pathlen){
        for(int i=0;i<paths.size();i++){
            vector<string> tmp;
            if(paths[i].size()==pathlen){
                for(int j=0;j<paths[i].size();j++)
                    tmp.push_back(wordList[paths[i][j]]);
                ans.push_back(tmp);
            }
        }
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
//"qa"
//"sq"
//["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]