//tag: Backtracking 回溯
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int subsum = 0;
        vector<int> sofar;
        combinationSum(candidates,target,subsum,sofar,ans);
        return ans;

    }
    void combinationSum(vector<int>& candidates,int target,int subsum,vector<int> sofar,vector<vector<int>> &ans){
    	if(subsum==target){
    		sort(sofar.begin(),sofar.end());
    		if(find(ans.begin(),ans.end(),sofar)==ans.end())
    			ans.push_back(sofar);
    	}else if(subsum<target){
    		for(int i=0;i<candidates.size();i++){
    			int opt = candidates[i];
    			if(subsum+opt<=target){
    				sofar.push_back(opt);
    				subsum+=opt;
    				combinationSum(candidates,target,subsum,sofar,ans);
    				sofar.pop_back();
    				subsum-=opt;
    			}
    		}
    	}

    }
};