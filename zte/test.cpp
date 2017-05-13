#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<climits>
#include<tuple>
#include<ctime>

using namespace std;

typedef pair<int, int> Edge;
typedef tuple<int, int, int> Evaluation;
typedef vector<int> Path;

//Path结构体  
struct PathNode  
{  
	Path path;
	Evaluation evaluation;
	PathNode() : path(), evaluation() {}
	PathNode(Path p, Evaluation e) : path(p), evaluation(e) {}
};

struct NextHop{
	int nodeID;
	int cost;
	bool isEnd;
	bool isGreenNode;
	bool isGreenEdge;
	NextHop() {}
	bool operator < (const NextHop & hop){
		if(isEnd > hop.isEnd) return true;
		if( isGreenEdge  > hop.isGreenEdge || 
			isGreenEdge == hop.isGreenEdge && isGreenNode  > hop.isGreenNode ||
			isGreenEdge == hop.isGreenEdge && isGreenNode == hop.isGreenNode && cost < hop.cost )
			return true;
		return false; 
	}
};

class Solution {
public:
	
	int N;
	vector<vector<int>> board;
	vector<vector<int>> neighbor;
	
	int start;
	int end;
	vector<Edge> redEdges;
	map<Edge, int> greenEdges;
	map<int, int> greenNodes;
	int maxHop;
	int mustPass;   //# of 约束条件 

	int curCost;
	int curLoss;    //# of 约束条件  -  # of 已满足的约束
	Path curPath;
	PathNode curMax;
	vector<PathNode> optimalPaths;

	clock_t st, et;  //time keeper 
	
	void init(){
		
		freopen("board.txt","r",stdin);

		
		cout<<"set Num Of Nodes:"<<endl;
		cin>>N;
		cout<<N<<endl;
		
		cout<<"set board:"<<endl;
		board.resize(N, vector<int>(N,-1) );
		neighbor.resize(N);
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				cin>>board[i][j];
				cout<<board[i][j]<<' ';
				if(0 < board[i][j]) neighbor[i].push_back(j);
			}			
			cout<<endl;
		}

		int n, n1, n2;
		mustPass = 0;
		
		//set Start & End Node  0 17
		cout<<"set Start & End Node: "<<endl;
		cin>>start>>end;
		cout<<start<<' '<<end;
		
		//set constraints:
		//set Red Edges  (11, 12)
		cout<<endl<<"set Red Edges: "<<endl;
		cin>>n;
		for(int i=0; i<n; ++i){
			cin>>n1>>n2;
			cout<<'('<<n1<<", "<<n2<<") ";
			board[n1][n2] = -1;
			board[n2][n1] = -1;
			neighbor[n1].erase( find(neighbor[n1].begin(), neighbor[n1].end(), n2) );
			neighbor[n2].erase( find(neighbor[n2].begin(), neighbor[n2].end(), n1) );
		}
		
		//set Green Edges  (2, 4) , (13, 14)
		cout<<endl<<"set Green Edges: "<<endl;
		cin>>n;
		mustPass += n;
		for(int i=0; i<n; ++i){
			cin>>n1>>n2;
			cout<<'('<<min(n1, n2)<<", "<<max(n1, n2)<<") ";
			Edge e1( min(n1, n2), max(n1, n2) );
			greenEdges[e1] = 0;
		} 

		//set Green Nodes  7, 12
		cout<<endl<<"set Green Nodes: "<<endl;
		cin>>n;
		mustPass += n;
		for(int i=0; i<n; ++i){
			cin>>n1;
			cout<<n1<<' ';
			greenNodes[n1] = 0;	
		}
		
		cout<<endl<<"set maxHop: "<<endl;
		cin>>maxHop;
		cout<<maxHop<<endl;				
	}
	
	int getNextHop(vector<NextHop> & hopList, int st){
		
		vector<int> itsNeighbor = neighbor[st];
		NextHop tmp;
		
		for(auto &next:itsNeighbor){
		
			tmp.nodeID = next;
			
			tmp.cost = board[st][next];
			if(next == end) tmp.isEnd = 1;
			else tmp.isEnd = 0;
			
			if( greenNodes.count(next) && 0 == greenNodes[next] ) tmp.isGreenNode = 1;
			else tmp.isGreenNode = 0;
			
			Edge temp(min(st, next), max(st, next));
			if( greenEdges.count(temp) && 0 == greenEdges[temp] ) tmp.isGreenEdge = 1;
			else tmp.isGreenEdge = 0;
			
			hopList.push_back(tmp);
		}
		
		sort(hopList.begin(), hopList.end());  //根据启发式搜索策略  对下一跳节点排序 
		return hopList.size();
	}
	
	//状态更新 
	void update(int &st, int &next){
		curPath.push_back(next);
		curCost += board[st][next];
		
//		if( greenNodes.count(next) ){
//			if( 0 == greenNodes[next] ){ ++greenNodes[next]; --curLoss; }
//			else ++greenNodes[next];
//		} 
//		Edge temp(min(st, next), max(st, next));
//		if( greenEdges.count(temp) ){
//			if( 0 == greenEdges[temp] ){ ++greenEdges[temp]; --curLoss; }
//			else ++greenEdges[temp];
//		}
//		
		
		// more concise
		if( greenNodes.count(next) && 1 == ++greenNodes[next] ) --curLoss;
		Edge temp(min(st, next), max(st, next));
		if( greenEdges.count(temp) && 1 == ++greenEdges[temp] ) --curLoss;
	}
	
	//还原现场 
	void resotre(int &st, int &next){
		curPath.pop_back();
		curCost -= board[st][next];
		
		if( greenNodes.count(next) && 0 == --greenNodes[next] ) ++curLoss;
		Edge temp(min(st, next), max(st, next));
		if( greenEdges.count(temp) && 0 == --greenEdges[temp] ) ++curLoss;
	}
			
			
	void dfs(int st, int ed, int step, int maxHop){
		
		if(!curMax.path.empty() && curCost > get<1>(curMax.evaluation))
			return;
		
		if(st==ed){
			//record solution
			if(curLoss == 0){
				if(curMax.path.empty()){
					curMax.path = curPath;
					curMax.evaluation = make_tuple(curLoss, curCost, step);
					optimalPaths.push_back(curMax);
					
					tock();
					 
					printPath(curPath);
				}else if( curCost < get<1>(curMax.evaluation) ){
					curMax.path = curPath;
					curMax.evaluation = make_tuple(curLoss, curCost, step);
					optimalPaths.clear();
					optimalPaths.push_back(curMax);
					
					tock();
					
					printPath(curPath);		
				}else if( curCost == get<1>(curMax.evaluation) ){
					optimalPaths.emplace_back(curPath, make_tuple(curLoss, curCost, step));
				}
			}
		}
				
		if(step>=maxHop) return;		
		
		vector<NextHop> hopList;
		int next;
		int nHop = getNextHop(hopList, st);
		
		for(int i = 0; i < nHop; ++i){	
			next = hopList[i].nodeID;
			update(st, next);
			dfs(next, ed, step+1, maxHop);
			resotre(st, next);
		}
				
	}
	
    void solve() {
		
		init();
				
		tick();
		
		curPath.push_back(start);
		curCost = 0;
		curLoss = mustPass;
		dfs(start, end, 1, maxHop);
    
    	
    	tock();	cout<<" to find Optimal Paths: ";
    
    	cout<<endl<<"Print Optimal Paths: "<<endl;
    	if(optimalPaths.empty()) cout<<"NO Paths!"<<endl;
    	else{
    		int cnt = 0;
			for(auto e:optimalPaths){
				cout<<'#'<<setw(2)<<setfill('0')<<++cnt<<": ";
				cout<<" loss: "<<get<0>(e.evaluation); 
				cout<<" cost: "<<get<1>(e.evaluation);
				cout<<" step: "<<get<2>(e.evaluation); 
				cout<<" path: ";
				for(auto ee:e.path){
					cout<<ee<<" ";
				}
				cout<<endl;
			}
		}
    }
    
    
    void printPath(vector<int> &p){
    	cout<<" curMax.path: ";
    	for(auto &e:p)
    		cout<<e<<" ";
		cout<<endl;
	}
	
	
	void tick(){
		st = clock();
	}
	
	void tock(){
		et = clock() - st;
    	cout<<endl<<"it takes(seconds): "<<((float)et)/CLOCKS_PER_SEC;	
	}
    
};


int main(){
	
	Solution test;
	test.solve();
		
	return 0;
}



