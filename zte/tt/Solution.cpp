#include "Solution.h"

//Get sorted next hop node list according to Heuristic search strategy
//Return : # of next hop nodes
int Solution::getNextHopList(vector<NextHop> & hopList, int st){
	vector<int> itsNeighbor = neighbor[st];
	NextHop tmp;
	
	for(auto &next:itsNeighbor){
		int temp = pairingFunc( min(st, next), max(st, next) ) + N; //encode edge(st, next) into a unique single number
		tmp.nodeID = next;
		tmp.cost   = board[st][next];
		tmp.isEnd  = ( next == end );
		tmp.isGreenNode = ( 0 == constraints[next] );
		tmp.isGreenEdge = ( 0 == constraints[temp] );
		hopList.push_back(tmp);
	}
	
	sort(hopList.begin(), hopList.end());  //sort nexthop node list according to Heuristic search strategy
	return hopList.size();
}

//Update state
void Solution::update(int st, int next){
	curPath.push_back(next);
	curCost += board[st][next];
	int temp = pairingFunc( min(st, next), max(st, next) ) + N; //encode edge(st, next) into a unique single number
	if( constraints[next] >= 0 && 1 == ++constraints[next] ) --curLoss;
	if( constraints[temp] >= 0 && 1 == ++constraints[temp] ) --curLoss;
}

//Restore state
void Solution::resotre(int st, int next){
	curPath.pop_back();
	curCost -= board[st][next];
	int temp = pairingFunc( min(st, next), max(st, next) ) + N; //encode edge(st, next) into a unique single number
	if( constraints[next] >= 0 && 0 == --constraints[next] ) ++curLoss;
	if( constraints[temp] >= 0 && 0 == --constraints[temp] ) ++curLoss;
}

//DFS to find optimal path	
void Solution::dfs(int st, int ed, int step, int maxHop){
	if(!curMax.path.empty() && curCost > get<1>(curMax.evaluation)) return; //trim
	
	//Record solution ( looks Tedious T_T )
	if(st==ed){
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
			
	if(step>=maxHop) return; //boundary conditions	
	
	vector<NextHop> hopList;
	int next; //numberID of next hop node
	//get sorted next hop node list and stored in hopList, nHop = hopList.size()
	int nHop = getNextHopList(hopList, st); 
	
	for(int i = 0; i < nHop; ++i){	
		next = hopList[i].nodeID;
		update(st, next);
		dfs(next, ed, step+1, maxHop);
		resotre(st, next);
	}			
}

void Solution::solve() {
	init();		//set board and constraints
	tick();		//start timer
	
	curPath.push_back(start);
	curCost = 0;
	curLoss = mustPass;
	dfs(start, end, 1, maxHop); //call dfs() to find solution

	tock();	cout<<" to find Optimal Paths: ";	//stop timer
		
	printOptimalPath(); //print solution
}


//-----------------Helper Functions---------------
void Solution::setBoard(){
	cout<<"set Num Of Nodes:"<<endl;
	cin>>N;
	cout<<N<<endl;
	cout<<"set board:"<<endl;
	board.resize( N, vector<int>(N,-1) );
	neighbor.resize(N);
	constraints.resize( pairingFunc( N-2, N-1 ) + N + 1, -1 );
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cin>>board[i][j];
			cout<<board[i][j]<<' ';
			if(0 < board[i][j]) neighbor[i].push_back(j);
		}			
		cout<<endl;
	}
}
void Solution::setConstraints(){
	int n, n1, n2;
	mustPass = 0;
	
	//set Start & End Node  e.g. 0 17
	cout<<"set Start & End Node: "<<endl;
	cin>>start>>end;
	cout<<start<<' '<<end;	
	//set Red Edges  e.g. 11 12
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
	//set Green Edges  e.g. 2 4   13 14
	cout<<endl<<"set Green Edges: "<<endl;
	cin>>n;
	mustPass += n;
	for(int i=0; i<n; ++i){
		cin>>n1>>n2;
		cout<<'('<<min(n1, n2)<<", "<<max(n1, n2)<<") ";
		constraints[ pairingFunc( min(n1, n2), max(n1, n2) ) + N ] = 0;
	}
	//set Green Nodes  e.g. 7 12
	cout<<endl<<"set Green Nodes: "<<endl;
	cin>>n;
	mustPass += n;
	for(int i=0; i<n; ++i){
		cin>>n1;
		cout<<n1<<' ';
		constraints[n1] = 0;
	}
	//set maxHop  e.g. 9
	cout<<endl<<"set maxHop: "<<endl;
	cin>>maxHop;
	cout<<maxHop<<endl;	
}
void Solution::printOptimalPath(){
	cout<<endl<<"Print Optimal Paths: "<<endl;
	if(optimalPaths.empty()) cout<<"NO Paths!"<<endl;
	else{
		int cnt = 0;
		for(auto e:optimalPaths){
			cout<<'#'<<setw(3)<<setfill('0')<<++cnt<<": ";
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

