class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    	vector<int> ans = vector<int>();
    	bool hasnoback = true;
        vector<vector<int> > adjl(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){//初始化邻接表
            adjl[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int> color(numCourses);//标记颜色，0未发现，1发现未访问，2访问过
        vector<int> fa(numCourses);//父亲
        vector<int> d(numCourses);//发现时间戳
        vector<int> f(numCourses);//访问时间戳
        int timestamp = 0;
        for(int v=0;v<numCourses;v++){//初始化辅助空间
            color[v] = 0;
            fa[v] = -1;
        }
        list<int> topu = list<int>();//拓扑排序后的顶点序列
        for(int u=0;u<numCourses;u++){
            if(color[u]==0){
                dfsvisit(adjl,u,color,fa,d,f,timestamp,topu,hasnoback);
            }
        }
        if(hasnoback){
        	for (list<int>::iterator it=topu.begin(); it != topu.end(); ++it){
	        	ans.push_back(*it);
	        }
        }       
        return ans;
    }
    void dfsvisit(vector<vector<int>>& adjl,int u,vector<int>& color,vector<int>& fa,vector<int>& d,vector<int>& f,int &timestamp,list<int>& topu,bool &hasnoback){
        color[u] = 1;
        d[u] = ++timestamp;
        for(int i=0;i<adjl[u].size();i++){
            int v = adjl[u][i];
            if(color[v]==0){
                fa[v] = u;
                dfsvisit(adjl,v,color,fa,d,f,timestamp,topu,hasnoback);
            }else if(color[v]==1){//只要遇到发现未结束的一定是遇到父辈，所以有回路
                hasnoback = false;
            }
        }
        color[u] = 2;
        f[u] = ++timestamp;
        topu.push_front(u);
    }    
};