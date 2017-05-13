#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tuple>
#include<ctime>

using namespace std;

/*
Triple(loss, cost, step) of a path
	loss : # of Constraints  -  # of Satisfied Constraints
	cost : sum of edge cost of a path
	step : # of nodes in a path
*/
typedef tuple<int, int, int> Evaluation;
typedef vector<int> Path;

//Path and its evaluation
struct PathNode  
{  
	Path path;
	Evaluation evaluation;
	PathNode() : path(), evaluation() {}
	PathNode(Path p, Evaluation e) : path(p), evaluation(e) {}
};
//Next hop Nodes for Heuristic search strategy
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
private:
	int N;	// # of nodes ( all nodes are numbered from 0 ~ N-1 )
	vector<vector<int>> board; // adjacency matrix ( board[i][j] = the cost of edge(i, j), board[i][j] = -1 means blocked )
	vector<vector<int>> neighbor; // neighbour[i] stores neighbor nodes of node(i) 
	int start;	// start node
	int end;	// end node
	vector<int> constraints;	
	int maxHop;		// # of nodes in a path must <= maxHop
	int mustPass;	// # of Constraints
	int curCost;	// cost of curPath
	int curLoss;	// # of Constraints  -  # of Satisfied Constraints
	Path curPath;
	PathNode curMax; // the current optimal solution
	vector<PathNode> optimalPaths;
	clock_t stime, etime;	// timer variables 

public:
	//Set board and constraints
	void init(){ freopen("board.txt","r",stdin); setBoard(); setConstraints(); fclose(stdin); }
	//Get sorted next hop node list according to Heuristic search strategy
	int getNextHopList(vector<NextHop> & hopList, int st);
	//Update state
	void update(int st, int next);
	//Restore State 
	void resotre(int st, int next);	
	//DFS to find optimal path
	void dfs(int st, int ed, int step, int maxHop);
	//Init, search and print solution
    void solve();
    
    
    //------------------Helper Functions-----------------
	void setBoard(); void setConstraints();
	//Print optimal path
	void printOptimalPath();
	//Print path
    void printPath(vector<int> &p){
    	cout<<" curMax.path: ";
    	for(auto &e:p)
    		cout<<e<<" ";
		cout<<endl;
	}
	//Start timer
	void tick(){
		stime = clock();
	}
	//Stop timer & print elapsed time (in seconds)
	void tock(){
		etime = clock() - stime;
    	cout<<endl<<"it takes(seconds): "<<((float)etime)/CLOCKS_PER_SEC;	
	}
	//Pairing function : uniquely encode two natural numbers into a single natural number
	int pairingFunc(int k1, int k2){
		return (k1+k2)*(k1+k2+1)/2 + k2;
	}
};

