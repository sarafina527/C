class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	vector<int> ans = vector<int>();
        for(int i=0;i<nums.size();i++){
        	if(nums[i]!=i+1){
        		int t = nums[i];
        		nums[i] = nums[t-1];
        		nums[t-1] = t;
        	}
        }
        for(int i=0;i<nums.size();i++){
        	if(nums[i]!=i+1){
        		ans.push_back(i+1);
        	}
        }
        return ans;
    }
};