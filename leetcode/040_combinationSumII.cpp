class Solution {
public:
    struct comp  
	{  
	    bool operator ()(const vector<int> &v1, const vector<int> &v2)  
	    {  
	        for(int i=0;i<v1.size()&&i<v2.size();i++){
	            if(v1[i]==v2[i])
	                continue;
	            else
	                return v1[i]<v2[i];
	        }
	        return v1.size()<v2.size();
	    }  
	};
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int subsum = 0;
        vector<int> sofar;
        set<vector<int>,comp> anset;
        combinationSum(candidates,target,subsum,sofar,anset);
        ans.assign(anset.begin(), anset.end());
        return ans;

    }
    void combinationSum(vector<int> candidates,int target,int subsum,vector<int> sofar,set<vector<int>,comp> &ans){
    	if(subsum==target){
    		sort(sofar.begin(),sofar.end());
    		ans.insert(sofar);
    	}else if(subsum<target){
    		for(int i=0;i<candidates.size();i++){
    			int opt = candidates[i];
    			if(subsum+opt<=target){
    				vector<int> next = sofar;
    				next.push_back(opt);
    				vector<int> rest = candidates;
    				rest.erase(rest.begin()+i);
    				combinationSum(rest,target,subsum+opt,next,ans);
    			}
    		}
    	}

    }
    
};