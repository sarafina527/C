class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans = vector<int>();
        map<int,int> has = map<int,int>();
        for (int i = 0; i < nums.size(); ++i)
        {
        	if(has.find(nums[i])==has.end()){
        		has[nums[i]] = 1;
        	}else{
        		has[nums[i]]++;
        		ans.push_back(nums[i]);
        	}
        }
        return ans;

    }
};