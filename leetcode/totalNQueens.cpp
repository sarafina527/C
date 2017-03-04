class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> sofar
        countNQueen(sofar,n,ans);
        return ans;
    }
    void countNQueen(vector<int> sofar,int n,int &ans){
    	if(sofar.size()==n){
    		ans++;
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
};