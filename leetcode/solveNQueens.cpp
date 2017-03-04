class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> sofar;
        putQueen(sofar,n,ans);
        return ans;
    }
    void putQueen(vector<int> sofar,int n,vector<vector<string>> &ans){
    	if(sofar.size()==n){
    		ans.push_back(construct(sofar));
    	}else{
    		for(int i=0;i<n;i++){
    			sofar.push_back(i);
    			if(!conflict(sofar))
    				putQueen(sofar,n,ans);
    			sofar.pop_back();
    		}
    	}
    }
    bool conflict(vector<int> sofar){
    	map<int,int> h;
    	map<int,int> lb;
    	map<int,int> lt;
    	for(int i=0;i<sofar.size();i++){
    		if(h.find(sofar[i])!=h.end()||lb.find(sofar[i]+i)!=lb.end()||lt.find(sofar[i]-i)!=lt.end())
    			return true;
    		else{
    			h[sofar[i]]++;
    			lb[sofar[i]+i]++;
    			lt[sofar[i]-i]++;
    		}
    	}
    	return false;
    }
    vector<string> construct(vector<int> sofar){
    	vector<string> ans;
    	for(int i=0;i<sofar.size();i++){
    		string tmp(sofar.size(),'.');
    		tmp[sofar[i]]='Q';
    		ans.push_back(tmp);
    	}
    	return ans;
    }
};