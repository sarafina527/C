class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        findTargetSumWays(nums,0,0,S,ans);
        return ans;
    }
    void findTargetSumWays(vector<int>& nums,int p,int sofar,int S,int &ans){
    	if(p==nums.length){
    		if(sofar==S) 
    			ans++;
    	}else{
    		findTargetSumWays(nums,p+1,sofar+nums[p],S,ans);
    		findTargetSumWays(nums,p+1,sofar-nums[p],S,ans);
    	}
    }
};