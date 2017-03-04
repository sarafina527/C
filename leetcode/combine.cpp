class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> rest;
        for(int i=1;i<=n;i++){
        	rest.push_back(i);
        }
        vector<int> sofar;
        combine(rest,k,sofar,ans);
        return ans;

    }
    void combine(vector<int> rest,int k,vector<int> sofar,vector<vector<int>> &ans){
    	if(k==0){
    		ans.push_back(perm(sofar));
    	}else if(rest.size()==k){
    		for(int i=0;i<k;i++){
    			sofar.push_back(rest[i]);
    		}
    		ans.push_back(perm(sofar));
    	}else{
    		
    		int d = rest.front();
			rest.erase(rest.begin());
			sofar.push_back(d);
			combine(rest,k-1,sofar,ans);
			sofar.pop_back();
			combine(rest,k,sofar,ans);
			
    	}
    }
    
};