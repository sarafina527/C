//126. Word Ladder II
//tag: BFS ,dp ,Backtacking,Array,String
//问题描述：给定两个词beginword和endword，和字典，返回begin到end最短长度的变换序列s，变换：次只能更改一个字母。每个转换字必须存在于单词列表中。初始节点不在字典中
//思路：1.构造图，可变换的两个词间有边连接(邻接表的形式)
//      2.用BFS遍历图，寻找最短路径,从后往前BFS记录每个节点的父亲节点
//      3.根据记录的父亲集，去DFS然后组合解
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        //0.找到起点和终点的下标
        int spos;
        vector<string>::iterator it = find(wordList.begin(),wordList.end(),beginWord);
        if(it==wordList.end()) wordList.push_back(beginWord);
        it = find(wordList.begin(),wordList.end(),beginWord);
        spos = it - wordList.begin();
        it = find(wordList.begin(),wordList.end(),endWord);
        if(it==wordList.end()) return ans;//特殊情况终点不在字典中返回空路径   
        int epos = it - wordList.begin();//下标
        //1.构造邻接表形式的图
        int n = wordList.size();//节点数
        vector<set<int> > graph(n,set<int>());//最后一个节点存放开始节点
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(diffbits(wordList[i],wordList[j])==1){//构建邻接表
                    graph[i].insert(j);
                    graph[j].insert(i);
                }
            }
        }
        //2.BFS记录从后到前面的各个节点的父亲集
        map<int,set<int> >pi;
        bool flag = 0;
        int shlen = BFS(graph,epos,spos,pi,flag);
        //3.如何可达，则根据父亲集去DFS
        if(flag){
            vector<string> sofar;
            vector<bool> visit(n,0);
            DFS(sofar,spos,epos,visit,shlen,pi,wordList,ans);
        }
        return ans;
    }
    //2.BFS遍历图
    int BFS(vector<set<int> > &graph,int spos,int epos,map<int,set<int> >&pi,bool& flag){
        int n = graph.size();
        vector<bool> visit(n,0);//标记图是否已经遍历经过
        queue<int> q;
        int pathlen = 0;
        q.push(spos);
        while(!q.empty()){
            pathlen++;vector<int> curl;
            while(!q.empty()){//取出当前层次所有的节点
                int cur = q.front();q.pop();
                visit[cur] = 1;//标记访问
                if(cur==epos)//到终点则退出
                    flag = 1;
                curl.push_back(cur);
            }
            if(flag) break;
            for(int i=0;i<curl.size();i++){
                int cur = curl[i];
                set<int>::iterator it;
                for(it=graph[cur].begin();it!=graph[cur].end();it++){
                    int next = *it;
                    if(!visit[next]){
                        q.push(next);
                        pi[next].insert(cur);
                    }
                }
            }
        }
        return pathlen;
    }
    //3.DFS去组合路径
    void DFS(vector<string> sofar,int cur,int epos,vector<bool> visit,int pathlen,map<int,set<int> >&pi,vector<string>& wordList,vector<vector<string> > &ans){
        visit[cur] = 1;
        sofar.push_back(wordList[cur]);
        if(pi[cur].empty()){
            ans.push_back(sofar);
        }else{
            set<int>::iterator it;
            for(it=pi[cur].begin();it!=pi[cur].end();it++){
                int next = *it;
                if(!visit[next]){
                    DFS(sofar,next,epos,visit,pathlen,pi,wordList,ans);
                }
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