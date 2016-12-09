#include <iostream>
#include <vector>
#include <list>

using namespace std; 
/*
 * 实际是拓扑排序问题,利用DFS f[u]的逆序作为拓扑序列
 * 返回是否是DAG
 *[[4,0],[5,0],[11,0],[2,1],[4,1],[8,1],[5,2],[6,2],[9,2],[2,3],[6,3],[13,3],[7,4],[8,5],[12,5],[5,6],[7,8],[10,9],[11,9],[13,10],[9,12]]
 */
class Solution {
public:
    list<int> topuSort(int numCourses, vector<pair<int, int> >& prerequisites) {
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
        		dfsvisit(adjl,u,color,fa,d,f,timestamp,topu);
        	}
        }
        for (list<int>::iterator it=topu.begin(); it != topu.end(); ++it)
    		cout << ' ' << *it;
        cout<<endl;
        print_path(adjl,fa,0,11);
    	return topu;
    }
    void dfsvisit(vector<vector<int> >& adjl,int u,vector<int>& color,vector<int>& fa,vector<int>& d,vector<int>& f,int &timestamp,list<int>& topu){
    	color[u] = 1;
    	d[u] = ++timestamp;
    	for(int i=0;i<adjl[u].size();i++){
    		int v = adjl[u][i];
    		if(color[v]==0){
    			fa[v] = u;
    			dfsvisit(adjl,v,color,fa,d,f,timestamp,topu);
    		}
    	}
    	color[u] = 2;
    	f[u] = ++timestamp;
    	topu.push_front(u);
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
	int numCourses = 14;
	vector<pair<int,int> > edges;
	edges.push_back(pair<int,int>(4,0));
	edges.push_back(pair<int,int>(5,0));
	edges.push_back(pair<int,int>(11,0));
	edges.push_back(pair<int,int>(2,1));
	edges.push_back(pair<int,int>(4,1));
	edges.push_back(pair<int,int>(8,1));
	edges.push_back(pair<int,int>(5,2));
	edges.push_back(pair<int,int>(6,2));
	edges.push_back(pair<int,int>(9,2));
	edges.push_back(pair<int,int>(2,3));
	edges.push_back(pair<int,int>(6,3));
	edges.push_back(pair<int,int>(13,3));
	edges.push_back(pair<int,int>(7,4));
	edges.push_back(pair<int,int>(8,5));
	edges.push_back(pair<int,int>(12,5));
	edges.push_back(pair<int,int>(5,6));
	edges.push_back(pair<int,int>(7,8));
	edges.push_back(pair<int,int>(10,9));
	edges.push_back(pair<int,int>(11,9));
	edges.push_back(pair<int,int>(13,10));
	edges.push_back(pair<int,int>(9,12));
    Solution sl = Solution();
	sl.topuSort(numCourses,edges);


}
