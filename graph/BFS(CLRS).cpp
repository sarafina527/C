#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std; 
/*
 * 实际是拓扑排序问题,利用DFS f[u]的逆序作为拓扑序列
 * 返回是否是DAG
 *[[4,0],[5,0],[11,0],[2,1],[4,1],[8,1],[5,2],[6,2],[9,2],[2,3],[6,3],[13,3],[7,4],[8,5],[12,5],[5,6],[7,8],[10,9],[11,9],[13,10],[9,12]]
 */
class Solution {
public:
    void solve(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > adjl(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){//初始化邻接表，无向图
        	adjl[prerequisites[i].second].push_back(prerequisites[i].first);
            adjl[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> color(numCourses);//标记颜色，0未发现，1发现未访问，2访问过
        vector<int> fa(numCourses);//父亲
        vector<int> d(numCourses);//距离
        
        for(int v=0;v<numCourses;v++){//初始化辅助空间
            color[v] = 0;
            fa[v] = -1;
            d[v] = INT_MAX;
        }
        int cc=0;
        for(int u=0;u<numCourses;u++){
        	if(color[u]==0){
                cc++;
        		BFS(adjl,u,color,fa,d);
        	}
        }
        cout<<"connected component count is "<<cc<<endl;
        print_path(adjl,fa,1,3);
        
    }
    void BFS(vector<vector<int> >& adjl,int s,vector<int>& color,vector<int>&fa,vector<int>&d){
        queue<int> Q = queue<int>();
        Q.push(s);//源点入队
    	color[s] = 1;
        d[s] = 0;
    	while(!Q.empty()){
            int u = Q.front();
            cout<<u<<"\t";
            Q.pop();
            for(int i=0;i<adjl[u].size();i++){//寻找所有当前结点的邻接点
                int v = adjl[u][i];
                if(color[v]==0){//当未发现过，入队
                    Q.push(v);
                    color[v] = 1;
                    fa[v] = u;
                    d[v] = d[u]+1;
                }

            }
            color[u] = 2;
        }
    }
    void print_path(vector<vector<int> >& adjl,vector<int>& fa,int s,int v){
        if(v==s){
            cout<<s<<'\t';
        }else{
            if(fa[v]!=-1){
                print_path(adjl,fa,s,fa[v]);
                cout<<v<<'\t';
            }else{
                cout<<"no path"<<endl;
            }
        }
    }
};

int main(){
	int numCourses = 8;
	vector<pair<int,int> > edges;
	edges.push_back(pair<int,int>(4,0));
	edges.push_back(pair<int,int>(5,1));
	edges.push_back(pair<int,int>(5,2));
	edges.push_back(pair<int,int>(2,3));
	edges.push_back(pair<int,int>(2,6));
	edges.push_back(pair<int,int>(3,6));
	edges.push_back(pair<int,int>(5,6));
    edges.push_back(pair<int,int>(7,6));
	edges.push_back(pair<int,int>(7,3));
    Solution sl = Solution();
	sl.solve(numCourses,edges);


}
